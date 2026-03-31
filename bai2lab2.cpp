#include <iostream>
#include <cmath>
using namespace std;

class PhanSo {
private:
    int iTu;
    int iMau;

    // Hàm phụ trợ tìm Ước chung lớn nhất
    int UCLN(int a, int b) {
        a = abs(a); b = abs(b);
        if (a == 0 || b == 0) return a + b;
        while (a != b) {
            if (a > b) a -= b;
            else b -= a;
        }
        return a;
    }

public:
    // Hàm khởi tạo (Constructor)
    PhanSo(int tu = 0, int mau = 1) : iTu(tu), iMau(mau) {}

    void Nhap() {
        cout << "Nhap tu so: "; cin >> iTu;
        do {
            cout << "Nhap mau so (khac 0): "; cin >> iMau;
            if (iMau == 0) cout << "Mau so phai khac 0. Vui long nhap lai!" << endl;
        } while (iMau == 0);
    }

    void Xuat() {
        if (iMau == 1) cout << iTu;
        else cout << iTu << "/" << iMau;
    }

    void RutGon() {
        int uc = UCLN(iTu, iMau);
        iTu /= uc;
        iMau /= uc;
        // Đảm bảo mẫu số luôn dương
        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }

    PhanSo Tong(PhanSo ps2) {
        PhanSo kq;
        kq.iTu = this->iTu * ps2.iMau + ps2.iTu * this->iMau;
        kq.iMau = this->iMau * ps2.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Hieu(PhanSo ps2) {
        PhanSo kq;
        kq.iTu = this->iTu * ps2.iMau - ps2.iTu * this->iMau;
        kq.iMau = this->iMau * ps2.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Tich(PhanSo ps2) {
        PhanSo kq;
        kq.iTu = this->iTu * ps2.iTu;
        kq.iMau = this->iMau * ps2.iMau;
        kq.RutGon();
        return kq;
    }

    PhanSo Thuong(PhanSo ps2) {
        PhanSo kq;
        kq.iTu = this->iTu * ps2.iMau;
        kq.iMau = this->iMau * ps2.iTu;
        kq.RutGon();
        return kq;
    }

    // Hàm so sánh: trả về 1 nếu lớn hơn, -1 nếu nhỏ hơn, 0 nếu bằng
    int SoSanh(PhanSo ps2) {
        // Quy đồng mẫu số (chỉ lấy tử số để so sánh)
        int tu1 = this->iTu * ps2.iMau;
        int tu2 = ps2.iTu * this->iMau;
        if (tu1 > tu2) return 1;
        if (tu1 < tu2) return -1;
        return 0;
    }
};

int main() {
    PhanSo ps1, ps2, kq;
    
    cout << "Nhap phan so thu 1 " << endl;
    ps1.Nhap();
    cout << "Nhap phan so thu 2 " << endl;
    ps2.Nhap();

    cout << "\nPhan so 1: "; ps1.RutGon(); ps1.Xuat();
    cout << "\nPhan so 2: "; ps2.RutGon(); ps2.Xuat();
    cout << endl;

    kq = ps1.Tong(ps2); cout << "Tong: "; kq.Xuat(); cout << endl;
    kq = ps1.Hieu(ps2); cout << "Hieu: "; kq.Xuat(); cout << endl;
    kq = ps1.Tich(ps2); cout << "Tich: "; kq.Xuat(); cout << endl;
    kq = ps1.Thuong(ps2); cout << "Thuong: "; kq.Xuat(); cout << endl;

    int ss = ps1.SoSanh(ps2);
    if (ss == 1) cout << "Phan so 1 > Phan so 2" << endl;
    else if (ss == -1) cout << "Phan so 1 < Phan so 2" << endl;
    else cout << "Phan so 1 = Phan so 2" << endl;

    return 0;
}
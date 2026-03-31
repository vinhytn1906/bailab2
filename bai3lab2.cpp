#include <iostream>

using namespace std;

class SoPhuc {
private:
    double iThuc; // Phần thực
    double iAo;   // Phần ảo

public:
    // Khởi tạo
    SoPhuc(double thuc = 0, double ao = 0) : iThuc(thuc), iAo(ao) {}

    void Nhap() {
        cout << "Nhap phan thuc: "; cin >> iThuc;
        cout << "Nhap phan ao: "; cin >> iAo;
    }

    void Xuat() {
        if (iAo >= 0) {
            cout << iThuc << " + " << iAo << "i";
        } else {
            cout << iThuc << " - " << -iAo << "i";
        }
    }

    // Công thức: (a+bi) + (c+di) = (a+c) + (b+d)i
    SoPhuc Tong(SoPhuc sp2) {
        SoPhuc kq;
        kq.iThuc = this->iThuc + sp2.iThuc;
        kq.iAo = this->iAo + sp2.iAo;
        return kq;
    }

    // Công thức: (a+bi) - (c+di) = (a-c) + (b-d)i
    SoPhuc Hieu(SoPhuc sp2) {
        SoPhuc kq;
        kq.iThuc = this->iThuc - sp2.iThuc;
        kq.iAo = this->iAo - sp2.iAo;
        return kq;
    }

    // Công thức: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
    SoPhuc Tich(SoPhuc sp2) {
        SoPhuc kq;
        kq.iThuc = (this->iThuc * sp2.iThuc) - (this->iAo * sp2.iAo);
        kq.iAo = (this->iThuc * sp2.iAo) + (this->iAo * sp2.iThuc);
        return kq;
    }

    // Công thức chia: [(a+bi)(c-di)] / (c^2 + d^2)
    SoPhuc Thuong(SoPhuc sp2) {
        SoPhuc kq;
        double mau = (sp2.iThuc * sp2.iThuc) + (sp2.iAo * sp2.iAo);
        if (mau == 0) {
            cout << "(Loi: Chia cho 0) ";
            return kq;
        }
        kq.iThuc = ((this->iThuc * sp2.iThuc) + (this->iAo * sp2.iAo)) / mau;
        kq.iAo = ((this->iAo * sp2.iThuc) - (this->iThuc * sp2.iAo)) / mau;
        return kq;
    }
};

int main() {
    SoPhuc sp1, sp2, kq;

    cout << "--- Nhap so phuc 1 ---" << endl;
    sp1.Nhap();
    cout << "--- Nhap so phuc 2 ---" << endl;
    sp2.Nhap();

    cout << "\nSo phuc 1: "; sp1.Xuat(); cout << endl;
    cout << "So phuc 2: "; sp2.Xuat(); cout << endl;

    cout << "\nTong: "; kq = sp1.Tong(sp2); kq.Xuat(); cout << endl;
    cout << "Hieu: "; kq = sp1.Hieu(sp2); kq.Xuat(); cout << endl;
    cout << "Tich: "; kq = sp1.Tich(sp2); kq.Xuat(); cout << endl;
    cout << "Thuong: "; kq = sp1.Thuong(sp2); kq.Xuat(); cout << endl;

    return 0;
}
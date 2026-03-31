#include <iostream>
using namespace std;

class date {            // Lớp date để quản lý ngày tháng năm
private:
    int ngay, thang, nam;
public:
    void nhap() {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }
    // Hàm xuất ngày tháng năm
    void xuat() {
        cout << ngay << "/" << thang << "/" << nam << endl;
    }
    // Hàm kiểm tra năm nhuận
    bool kiemTraNamNhuan() {
        if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
            return true;
        }
        return false;
    }
    // Hàm tính số ngày trong tháng
    int soNgayTrongThang() {
        if (thang == 2) {
            if (kiemTraNamNhuan()) {
                return 29;
            }
            return 28;
        }
        else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }
    // Hàm tính ngày tháng năm tiếp theo
    void ngaytthangnamtieptheo() {
        ngay++;
        if (ngay > soNgayTrongThang()) {
            ngay = 1;
            thang++;
            if (thang > 12) {
                thang = 1;
                nam++;
            }
        }
    }
};
// Hàm main để kiểm tra chức năng của lớp date
int main() {
    date d;

    d.nhap(); 
    cout << "Ngay vua nhap: ";
    d.xuat();

    cout << "Ngay tiep theo: ";
    d.ngaytthangnamtieptheo();
    d.xuat();

    return 0;
}
#include <iostream>
using namespace std;

class ThoiGian {            // Lớp ThoiGian để quản lý giờ, phút, giây
private:
    int iGio, iPhut, iGiay;

public:
    void Nhap() { // Hàm nhập giờ, phút, giây với kiểm tra hợp lệ
        do {
            cout << "Nhap gio (0-23): ";
            cin >> iGio;
            if (iGio < 0 || iGio > 23) {
                cout << "Gio phai trong khoang 0-23. Vui long nhap lai!" << endl;
            }
        } while (iGio < 0 || iGio > 23);

        do {
            cout << "Nhap phut (0-59): ";
            cin >> iPhut;
            if (iPhut < 0 || iPhut > 59) {
                cout << "Phut phai trong khoang 0-59. Vui long nhap lai!" << endl;
            }
        } while (iPhut < 0 || iPhut > 59);

        do {
            cout << "Nhap giay (0-59): ";
            cin >> iGiay;
            if (iGiay < 0 || iGiay > 59) {
                cout << "Giay phai trong khoang 0-59. Vui long nhap lai!" << endl;
            }
        } while (iGiay < 0 || iGiay > 59);
    }

    void Xuat() {
    
        if (iGio < 10) cout << "0";
        cout << iGio << ":";
        
        if (iPhut < 10) cout << "0";
        cout << iPhut << ":";
        
        if (iGiay < 10) cout << "0";
        cout << iGiay;
    }

    void TinhCongThemMotGiay() {
        iGiay++; // Cộng thêm 1 giây
        
        if (iGiay >= 60) { // Nếu giây vượt quá 59
            iGiay = 0;     // Reset giây
            iPhut++;       // Tăng phút lên 1
            
            if (iPhut >= 60) { // Nếu phút vượt quá 59
                iPhut = 0;     // Reset phút
                iGio++;        // Tăng giờ lên 1
                
                if (iGio >= 24) { // Nếu giờ vượt quá 23
                    iGio = 0;     // Reset giờ sang ngày mới
                }
            }
        }
    }
};

int main() {
    ThoiGian tg;

    cout << "--- Nhap vao thoi gian ---" << endl;
    tg.Nhap();

    cout << "\nThoi gian ban dau: ";
    tg.Xuat();

    tg.TinhCongThemMotGiay();
    
    cout << "\nThoi gian sau khi cong 1 giay: ";
    tg.Xuat();
    cout << endl;

    return 0;
}
#include<bits/stdc++.h>
#include"quanli.cpp"
using namespace std;

class App {
private:
    DanhSachSinhVien dssv;

public:
    void menu() {
        int choice;
        do {
            cout << "\n=== Menu Quan Ly Sinh Vien ===\n";
            cout << "1. Nhap danh sach sinh vien\n";
            cout << "2. Xuat danh sach sinh vien\n";
            cout << "3. Them sinh vien\n";
            cout << "4. Xoa sinh vien\n";
            cout << "5. Tim kiem sinh vien\n";
            cout << "6. Sap xep danh sach sinh vien\n";
            cout << "7. Nhap danh sach sinh vien vao file\n";
            cout << "8. In danh sach sinh vien tu file ra\n";
            cout << "0. Thoat\n";
            cout << "Lua chon cua ban: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1: {
                    int n;
                    cout << "Nhap so luong sinh vien: ";
                    cin >> n;
                    cin.ignore();
                    dssv.nhapDanhSach(n);
                    break;
                }
                case 2:
                    dssv.xuatDanhSach();
                    break;
                case 3: {
                    SinhVien sv;
                    cin >> sv;
                    dssv.themSinhVien(sv);
                    break;
                }
                case 4: {
                    string keyword;
                    cout << "Nhap ho ten hoac ma sinh vien can xoa: ";
                    getline(cin, keyword);
                    dssv.xoaSinhVien(keyword);
                    break;
                }
                case 5: {
                    string keyword;
                    cout << "Nhap ho ten hoac ma sinh vien can tim: ";
                    getline(cin, keyword);
                    dssv.timKiemSinhVien(keyword);
                    break;
                }
                case 6:{
                    dssv.sapXepDanhSach();
                    cout << "Da sap xep danh sach sinh vien.\n";
                    break;
                    }
                case 7: {
                    string tenFile;
                    cout << "Nhap ten file de luu danh sach sinh vien: ";
                    getline(cin, tenFile);
                    dssv.ghiFile(tenFile);
                    break;
                }
                case 8: {
                    string tenFile;
                    cout << "Nhap ten file de doc danh sach sinh vien: ";
                    getline(cin, tenFile);
                    dssv.docVaInDanhSach(tenFile);
                    break;
                }

                case 0:
                    cout << "Thoat chuong trinh.\n";
                    break;
                default:
                    cout << "Lua chon khong hop le!\n";
            }
        } while (choice != 0);
    }
};
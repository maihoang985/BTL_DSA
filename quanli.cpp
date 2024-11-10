#include<bits/stdc++.h>
#include "sinh_vien.cpp"
using namespace std;

int cmpName(SinhVien a, SinhVien b){
    return a.getTen() < b.getTen();
}

int cmpDiem(SinhVien a, SinhVien b){
    return a.getdiem() > b.getdiem();
}

int cmpDiem2(SinhVien a, SinhVien b){
    return a.getdiem() < b.getdiem();
}

class DanhSachSinhVien {
private:
    list<SinhVien> danhSach;

public:
    void nhapDanhSach(int n) {
        for (int i = 0; i < n; i++) {
            SinhVien sv;
            cout << "Nhap thong tin sinh vien thu " << i + 1 << ":\n";
            cin >> sv;
            danhSach.push_back(sv);
        }
    }

    void xuatDanhSach() {
        cout << left;
         cout <<setw(31) << "Ho ten  " << "|"
       << setw(22) << "Ma SV  " << "|"
       << setw(32) << "Ngay sinh" << "|"
       << setw(7) << "Diem "  << "|" << endl;
        for (auto& sv : danhSach) {
            cout << sv;
        }
    }

    void themSinhVien(SinhVien& sv) {
        danhSach.push_back(sv);
    }

    void xoaSinhVien(string keyword) {
    for (auto it = danhSach.begin(); it != danhSach.end(); ) {
            if (it->getMaSV() == keyword || it->getHoTen() == keyword) {
                it = danhSach.erase(it); 
            } else {
                it++; 
            }
        }
    }
void timKiemSinhVien(string keyword) {
        bool found = false;
        for (auto& sv : danhSach) {
            if (sv.getHoTen() == keyword || sv.getMaSV() == keyword) {
                cout << sv << endl;
                found = true;
            }
        }
        if (!found) cout << "Khong tim thay sinh vien!\n";
    }
    
        void sapXepDanhSach() {
            int choice;
            cout << "1.Sap xep theo alphabets\n";
            cout << "2. Sap xep theo diem giam dan\n";
            cout << "3. Sap xep theo diem tang dan\n";
            cout << "Lua chon cua ban: ";
            cin >> choice;
            cin.ignore();
            switch (choice) {
                case 1: {
                     danhSach.sort(cmpName);
                    break;
                }
                case 2: {
                    danhSach.sort(cmpDiem);
                }
                case 3: {
                    danhSach.sort(cmpDiem2);
                }
                default:
                    cout << "Lua chon khong hop le!" << endl;
                    break;
            }
        }

    

    void ghiFile(string& tenFile) {
        ofstream fileOut(tenFile);
        if (fileOut.is_open()) {
            for (auto& sv : danhSach) {
                fileOut << sv.getHoTen() << "\n"
                        << sv.getMaSV() << "\n"
                        << sv.getngaySinh() << "\n"
                        << sv.getdiem() << "\n";
            }
            fileOut.close();
            cout << "Da luu danh sach sinh vien vao file " << tenFile << ".\n";
        } else {
            cout << "Khong mo duoc file " << tenFile << " de ghi.\n";
        }
    }

    void docVaInDanhSach(const string& tenFile) {
        cout << left;
        cout <<setw(31) << "Ho ten  " << "|"
       << setw(22) << "Ma SV  " << "|"
       << setw(32) << "Ngay sinh" << "|"
       << setw(7) << "Diem "  << "|" << endl;
    ifstream fileIn(tenFile);
    
    if (fileIn.is_open()) {
        danhSach.clear();
        
        while (!fileIn.eof()) {
            SinhVien sv;
            string hoten;
            getline(fileIn, hoten);
            sv.sethoten(hoten);

            string msv;
            getline(fileIn, msv);
            sv.setMaSV(msv);

            string birth;
            getline(fileIn, birth);
            sv.setngaySinh(birth);

            float score;
            fileIn >> score;
            sv.setdiem(score);
            
            fileIn.ignore(); 
            
            if (!fileIn.fail()) {
                danhSach.push_back(sv);
                cout << sv;
            }
        }
        
        fileIn.close();
        cout << "Da tai va in danh sach sinh vien tu file " << tenFile << ".\n";
    } else {
        cout << "Khong mo duoc file " << tenFile << " de doc.\n";
    }
}


};
//thêm sinh viên
//xóa sinh viên : qua
//tìm kiếm sinh viên : qua tên, msv
//file
//sắp xếp theo alpha b
//sắp xêp theo điểm trung bình

//họ tên, msv, điểm, 

#include<bits/stdc++.h>
using namespace std;

class SinhVien {
private:
    string hoTen;
    string maSV;
    string ngaySinh;
    float diem;

public:     
    SinhVien() {
    hoTen = "";
    maSV = "";
    ngaySinh = "";
    diem = 0.0;
}
    friend istream& operator>>(istream& is, SinhVien& sv) {
        cout << "Nhap ho ten: ";
        getline(is, sv.hoTen);
        cout << "Nhap ma sinh vien: ";
        getline(is, sv.maSV);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(is, sv.ngaySinh);
        cout << "Nhap diem: ";
        is >> sv.diem;
        is.ignore();
        return is;
    }
    friend ostream& operator<<(ostream& os, SinhVien& sv) {
    os << left;  
    os << setw(30) << sv.hoTen << " | "
       << setw(20) <<  sv.maSV << " | "
       << setw(30) <<  sv.ngaySinh << " | "
       << setw(5) <<  sv.diem << " |" << endl;
    return os;
    }
    string getTen() {
            string tmp="";
            for (int i = hoTen.size()-1; i >= 0; i--){
                if (hoTen[i] == ' ') break;
                tmp = hoTen[i] + tmp;
            }
            return tmp;
        }
    bool operator <(SinhVien other) {
                 return hoTen < other.hoTen;
            }
    bool operator ==(SinhVien& other){
            return 
            hoTen == other.hoTen
            && maSV == other.maSV
            && ngaySinh == other.ngaySinh
            && diem == other.diem;   
        }
    string getHoTen() { return hoTen; }
    string getMaSV() { return maSV; }
    string getngaySinh() { return ngaySinh; }
    float getdiem() { return diem; }
    void sethoten(string name){
        hoTen = name;
    }
    void setMaSV(string msv){
        maSV = msv;
    }
    void setngaySinh(string birth){
        ngaySinh = birth;
    }
    void setdiem(float score){
        diem = score;
    }
};


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TV{
    int maHang;
    string hangSanXuat;
    string tenTV;
    float donGia;
    int soLuong;
    public:
        friend istream &operator >> (istream &is, TV &tv) {
            is >> tv.maHang; fflush(stdin);
            // getline(is, tv.maHang);
            getline(is, tv.hangSanXuat);
            getline(is, tv.tenTV);
            is >> tv.donGia >> tv.soLuong;
            return is;
        }
        friend ostream &operator << (ostream &os, TV tv) {
            os << tv.maHang << " " << tv.hangSanXuat << " " << tv.tenTV << " " << tv.donGia << " " << tv.soLuong+"\n";
            return os;
        }
        int getMa() { return maHang; }
        float getGia() { return donGia; }
        int getLuong() { return soLuong; }
        string getHang() {return hangSanXuat; }
        string getTen() { return tenTV; }
        TV(int ma, string NSX, string ten, float gia, int so) : maHang(ma), hangSanXuat(NSX), tenTV(ten), donGia(gia), soLuong(so) {}
};

class DanhSach{
    vector<TV> tv;
    public:
        void themTV(TV &A) {
            tv.push_back(A);
        }
        void xoaTV(int ma) {
            for (auto it = tv.begin(); it != tv.end(); ++it) {
                if ((*it).getMa() == ma) {  
                    tv.erase(it); 
                    break;        
                }
            }
        }
        float tongHangHoa() {
            float s = 0;
            int count = 0;
            for (auto z : tv) {
                if (z.getLuong() == 0) count++;
                else s += z.getGia() * z.getLuong();
            }
            if (count == tv.size()) return 0;
            return s;
        }
        void inDanhSach() {
            for (auto z : tv) cout << z << "\n";
        }
        int getSize() { 
            return tv.size();
        }
        void bSearch(int &ma) {
            sort(tv.begin(), tv.end(), [](TV &a, TV &b) { return a.getMa() < b.getMa(); });
            int found = 0;
            int i = 0;
            int j = tv.size()-1;
            int mark;
            while(i <= j && found != 1) {
                int mid = (i+j)/2;
                if (tv[mid].getMa() == ma) found = 1;
                else {
                    if (ma < tv[mid].getMa()) j = mid-1;
                    else i = mid+1;
                }
                mark = mid;
            }
            if (found == 1) cout << tv[mark].getTen() << " "<< tv[mark] .getLuong() << " "<< tv[mark].getHang() <<" "<< tv[mark].getGia();
            else cout << "san pham ban tim khong co!\n";
        }
};

int main() {
    DanhSach ds1;
    TV A(123, "sony", "pre", 2.2, 2);
    TV B(124, "samsung", "galaxy", 2, 1);
    TV C(125, "iporn", "pro max", 4, 1);
    TV D(126, "rog", "ultra", 6, 1);
    TV E(127, "google", "pixel", 1, 2);
    ds1.themTV(A);
    ds1.themTV(B);
    ds1.themTV(C);
    ds1.themTV(D);
    ds1.themTV(E);
    ds1.inDanhSach();
    cout <<"tong tien hang la: "<< ds1.tongHangHoa() << endl;
    int code; cin >> code;
    ds1.bSearch(code);
    

    return 0;
}
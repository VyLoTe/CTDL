#include <iostream>
#include <vector> // nếu chữ số cuối của biển là chẵn
#include <list> //nếu chữ số cuối của biển là lẻ
#include <algorithm>
#include <string>
using namespace std;

class Car {
    string model;
    int year;
    string lP; //license plate : biển số
    string firm; 
    public:
        friend istream& operator>> (istream &is,  Car &c) {
            cout << "Nhap model xe: ";
            getline(is, c.model);
            cout << "Nhap nam san xuat: ";
            is >> c.year;
            is.ignore();
            cout << "Nhap so bien kiem soat: ";
            getline(is, c.lP);
            cout << "Nhap hang xe: ";
            getline(is, c.firm);
        }
        friend ostream& operator<<  (ostream &os,  Car &c) {
            cout << "Thong tin ve xe:\n";
            os << c.firm << ' ' << c.year << ' ' << c.model << ' '<< c.lP << '\n'; 
        }
        bool  operator< (const Car &c) {
            return this->year < c.year;
        }
        string getModel() { return model; }
        int getYear() { return  year; }
        string getLP() { return lP; }
        string getFirm() { return  firm; }
};

class carList {
    vector<Car> vCar;
    list<Car> lCar;
    bool isVector;
    public:
        void nhapDanhSach() {
            Car c;
            cout << "Nhap thong tin xe:\n";
            cin >> c;
            char lastChar = c.getLP().back();
            if (isdigit(lastChar)) {
                int lastNum = lastChar - '0';
                // kiểm tra chẵn hay lẻ để dùng vector hay list
                if (lastNum % 2== 0) {
                    isVector = true;
                    vCar.push_back(c);
                }
                else {
                    isVector = false;
                    lCar.push_back(c);
                }
            }
            else {
                cout << "The last char isn't  a digit\n";
            }
        }
        void xuatDanhSach() {
                for (auto z :  vCar) cout << z << ' ';
                cout << '\n';
                for (auto z : lCar) cout << z << ' ';
                cout << '\n';
        }
        void sapXepDanhSach() {
            if (isVector) sort(vCar.begin(),  vCar.end());
            else lCar.sort();
        }
        void maxNSX() {
            int max;
            if(isVector) {
                for (int i = 0; i <  vCar.size(); ++i) {
                    if (vCar[i].getYear() > max) {
                        max = vCar[i].getYear();
                    }
                }
            }
            else {
                for (auto& z : lCar) {
                    if (z.getYear() > max) {
                        max = z.getYear();
                    }
                }
            }
            cout << max << '\n';
        }
        void timKiemModel(string model) {
            if (isVector) {
                for (auto z : vCar) {
                    if (z.getModel().compare(model)==0) {
                        cout << "The information of car is: " << z.getFirm() << ' ' << z.getYear() << ' ' << z.getLP() << '\n';
                        return;
                    }
                }
                cout << "The car does not exsit!\n"; 
            }
            for (auto z : lCar) {
                    if (z.getModel().compare(model)==0) {
                        cout << "The infor  of car is: " << z.getFirm() << ' ' << z.getYear() << ' ' << z.getLP() << '\n';
                        return;
                    }
            }
            cout << "The car does not exsit!\n"; 
        }
        void themCar() {
            Car car;
            cin >> car;
            if (isVector) {
                vCar.push_back(car);
            }
            else lCar.push_back(car);
        }
};

class MENU {
    carList clist;
    public:
        void menu() {
            int choice;
            carList list;
            do {
                cout << "\n----- MENU -----\n";
                cout << "1. Nhap danh sach o to\n";
                cout << "2. Xuat danh sach o to\n";
                cout << "3. Sap xep danh sach o to theo nam\n";
                cout << "4. Tim oto theo model\n";
                cout << "5. Thoat\n";
                cout << "Nhap lua chon: ";
                cin >> choice;
                cin.ignore();
                
                switch (choice) 
                {
                case 1:
                    list.nhapDanhSach();
                    break;
                case 2:
                    list.xuatDanhSach();
                    break;
                case 3:
                    list.sapXepDanhSach();
                    break;
                case 4: {
                    string model; 
                    cout << "Nhap ten model cua xe: ";
                    getline(cin, model);
                    list.timKiemModel(model);
                    break;
                }
                case 5:
                    cout << "Do you confirm exit? (y/n)";
                    char confirm; cin >> confirm;
                    if (confirm == 'y') return; 
                    break;
                default:
                    cout << "The option does not exsit";
                    break;
                }
            }while(true);
        }
};

int main() {
    MENU menu;
    menu.menu();
    return 0;
}
#include <iostream>
using namespace std;
// cai dat vector bang mang
template<class T>

class Vector
{
private:
    unsigned int cap, num;
    T *buff;
public:
    Vector() {cap= num = 0; buff = NULL;}
    Vector(unsigned int n) {
        num = cap = n;
        buff = new T[cap];
    }
    Vector(unsigned int n, T x) {
        num = cap = n;
        buff  = new T[cap];
        for (int i = 0; i < n; ++i) buff[i] = x;
    }
    ~Vector() {
        if(buff) delete[] buff;
    }
    friend istream& operator >> (istream &is, Vector<T> &v) {
        for (int i = 0; i < v.num; ++i) is >> v.buff[i];
        return is;
    }
    friend ostream& operator << (ostream &os, Vector<T> &v) {
        for (int i = 0; i < v.num; ++i) os << v.buff[i] << " ";
        os  << "\n";
        return os;
    }
    unsigned int size() { return num; }
    void pushBack(const T& x) {
        if (cap == num) {
            cap = (cap == 0) ? 1 : cap*2+1;
            T* newBuff = new T[cap];

            for (int i = 0; i < num; ++i) {
                newBuff[i] = buff[i];
            }
            delete[] buff;
            buff = newBuff;
        }
        buff[num] = x;
        ++num;
    }
    void pushFront(const T& x) {
        if (cap == num) {
            cap = (cap == 0) ? 1 : cap*2+1;
            T* newBuff = new T[cap];

            for (int i = 0; i <= num; ++i) {
                newBuff[i+1] = buff[i];
            }
            delete[] buff;
            buff = newBuff;
        }
        else {
            for (int i = 1; i <=  num; ++i) {
                buff[i] = buff[i-1];
            }
        }
        buff[0] = x;
        ++num;
    }
    void popBack() {
        if (num) --num;
    }
    void setNum() {
        this->num = num;
    }

    unsigned int getNum() const{
        return num;
    } 
    void setBuff() {
        this->buff = buff;
    }
    T* getBuff() const {
        return buff;
    }
    class Iterator {
        private:
            T *current;
        public:
            Iterator(T *ptr) : current(ptr) {} 
            T& operator*() { return *current; }
            Iterator& operator++() {
                ++current;
                return *this;
            }
            bool operator!=(const Iterator &it) const {
                return current != it.current;
            }
            Iterator operator+(int n) const {
                return Iterator(current + n);
            }

            Iterator operator-(int n) const {
                return Iterator(current - n);
            }

            // Allow conversion from Iterator to T*
            operator T*() const {
                return current;
            }    
            friend class Vector;
        };
    Iterator begin() {return Iterator(buff);}
    Iterator end() {return Iterator(buff+num);}
    T& operator[](unsigned int index) {
        return buff[index];
    }
    T& operator()  (unsigned int index) {
        return buff[index];
    }
    T& front() {return buff[0]; }
    T& back() {return buff[num-1];}
    unsigned int size() const {return num;}
    unsigned int max_size() const { return cap; }
    bool empty() const {
        return num == 0;  // Returns true if empty, otherwise false
    }

    void resize(unsigned int size) {
        T* newBuff = new T[size];
        for (unsigned int i = 0; i < size; ++i) {
            newBuff[i] = buff[i];
        }
        delete[] buff;
        buff = newBuff;
        num = size;
        cap = size;
    }
    void insert(Iterator pos, const T &x) {
        unsigned int index = pos.current - buff;
        if (num == cap) {
            cap = (cap == 0) ? 1 : cap*2+1;
            T* newBuff = new T[cap];

            for (int i = 0; i < index; ++i) {
                newBuff[i] = buff[i];
            }
            for (int i = index; i <= num; ++i) {
                newBuff[i+1] = buff[i];
            }
            delete[] buff;
            buff = newBuff;
        }
        else {
            for (int i = num; i > index; --i) {
                buff[i] = buff[i-1];
            }
        }
        buff[index] = x;
        ++num;
    }
};


int main() {
    Vector<int> a;
    // Vector<int> b(3,5);
    // cout << b;
    a.pushBack(12);
    a.pushBack(13);
    a.pushBack(14);
    a.pushBack(15);
    a.pushBack(16);
    a.popBack();
    cout << a;
    for (auto it = a.begin(); it !=  a.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    // cout << a[1] << endl;
    // cout << a[3] << endl;
    // cout << a.front() << endl;
    // cout << a.back();
    a.resize(2);
    a.pushFront(5);
    a.insert(a.begin()+1, 28);
    cout << a;
}
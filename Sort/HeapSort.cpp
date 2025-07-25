#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> b;

void Heapify(int i, int n) {
    int kt = 0;
    int max;
    int j = i;
    while(kt == 0 && 2 * j + 1 < n) 
    {
        if (2 * j + 2 >= n) max = 2 * j + 1;  
        else {
            if(a[2*j+1] < a[2*j+2]) max = 2*j+2;
            else max = 2*j+1;
        }
        if (a[j] < a[max]) {
            swap(a[j],a[max]);
            j = max;
        }
        else kt = 1;
    }
}

void HeapSort(int n) {
    for (int i = n/2 -1; i >= 0; --i)
        Heapify(i, n-1);

    for (int i = n-1; i >= 1; --i) {
        b.push_back(a[0]);
        swap(a[0], a[i]); 
        Heapify(0, i-1);
    }
    b.push_back(a[0]);
}

int main() {
    int c[] = {12, 13, 9, 25, 7, 31, 3, 37, 14, 22, 15};
    int n = sizeof(c)/sizeof(int);
    for (int i = 0; i < n; ++i) a.push_back(c[i]);
    HeapSort(n);
    for (auto z : b) cout << z << ' ';

    return 0;
}

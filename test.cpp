#include <bits/stdc++.h>
using namespace std;

int main() {
    int b[] = {1,2,3,4};
    int size = 4;
    int *a = new int[size];
    for (int i =0; i < 4; ++i) {
        a[i] = b[i];
    }
    
    for (int i = size; i > 0; --i) {
        a[i] = a[i-1];
    }
    a[0] = 9;
    size++;
    for (int i = 0; i < size; ++i) cout << a[i] << " ";

    return 0;
}

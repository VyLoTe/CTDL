#include <bits/stdc++.h>
using namespace std;

/*
ý tưởng quick sort:
-lấy ra phần tử ngoài cùng bên trái để làm mốc so sánh(x), đánh dấu phần tử thứ 2 là i (i chạy từ 1) và phần tử cuối là j (j chạy ngược từ
 n) 
-so sánh x với phần tử left+1:
    +nếu x < left +1, đem so sánh với right: -nếu right nhỏ hơn x thì swap left+1 với right
                                             -nếu right > x thì right-1 (dịch lên phía trc) và lại tiếp tục so sánh với x
                                             -điều kiện dừng là i > j 
    +nếu x > left+1: -left+1 điều kiện lặp là i <= j                                                   
    +khi mà x > right-m lập tức swap vị trí x với vị trí right-m và đánh dấu x dc sắp, tiép tục gọi đệ quy để có thể đánh dấu dc hết các 
    vị trí
*/

int partition(int a[], int left, int right) {
    int x = a[left];
    int i = left + 1;
    int j = right;
    int temp;
    do {
        while (i <=j && a[i] <= x) i++;
        while (i <= j && a[j] >= x) j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }while(i <= j);
    temp = a[left];
    a[left] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int left, int right) {
    int k;
    if (left < right) {
        k = partition(a, left, right);
        quickSort(a, left, k-1);
        quickSort(a, k+1, right);
    }
}

int main() {
    int a[] = {3, 5, 1, 9, 13, 4, 28, 0};
    quickSort(a, 0, 7);
    for (auto z : a) cout << z << " ";

    return 0;
}
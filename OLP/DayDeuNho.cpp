#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read input
    freopen("OLP.inp", "r", stdin);
    freopen("OLP.out", "w", stdout);

    int n, k, pos = -1;
    cin >> n >> k;

    vector<int> a(n);
    
    // Read the array and find the position of the first occurrence of 1
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1 && pos == -1) {
            pos = i; // Store the position of the first 1
        }
    }

    if (pos == -1) {
        cout << 0 << endl;
        return 0;
    }

    int right = pos;
    int left = pos;
    int steps = 0;
   
    while (right < n-1) {
        if (right > n-1) {
            ++steps;
            break;
        }
        right += k-1; // Move k steps to the right
        steps++;
    }

    while (left > 0) {
        if (left < 0) {
            steps++;
            break;
        }
        left -= k-1; // Move k steps to the left
        steps++;
    }

    cout << steps << endl;
    return 0;
}
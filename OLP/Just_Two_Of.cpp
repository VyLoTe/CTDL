#include <iostream>
#include <vector>
using namespace std;
#define ull unsigned long long

vector<ull> a;

bool check(ull x) {
	while (x != 0) {
		ull temp = x % 10;
		x /= 10;
		a.push_back(temp);
	}

	ull first = a[0];
    ull second = a[1];

 	ull temp;
    if (first == second) {
        for (size_t i = 2; i < a.size(); ++i) {
     		ull j = i+1;
     		if (a[i] != first || a[j] != first) {
     			if (a[i] != first) {
     				temp = i;
     				if (a[temp] != a[j+1] && a[j+1] != first) {
     					a.clear();
     					return false;
     				}
     			}
     			if (a[j] != first) {
     				temp = j;
     				if (a[temp] != a[j+1] && a[j+1] != first) {
     					a.clear();
     					return false;
     				}
     			}
     		}
     		if (a[i] != first && a[j] != first && a[i] != a[j]) {
     			a.clear();
     			return false;
     		}
        }
        return true;
    }

    else {
        for (size_t i = 2; i < a.size(); ++i) {
            if (a[i] != first && a[i] != second) { // Check if digits don't match the first two
            	a.clear();
                return false;
            }
        }
    }	

    a.clear();
    return true;
 }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("OLP.inp", "r", stdin);
    freopen("OLP.out", "w", stdout);

    ull N; cin >> N;
    int count = 0;
    for (ull i = 1; i <= N; ++i) {
    	if (check(i)) ++count;
    }

    cout << count;
    return 0;
}
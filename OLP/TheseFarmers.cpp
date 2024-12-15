#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if cows can be placed with at least 'minDist' between them
bool canPlaceCows(const vector<int>& positions, int cows, int minDist) {
    int count = 1;  // Place the first cow at the first position
    int lastPosition = positions[0];
    
    for (int i = 1; i < positions.size(); ++i) {
        if (positions[i] - lastPosition >= minDist) {
            count++;
            lastPosition = positions[i];
            if (count == cows) {
                return true;
            }
        }
    }
    return false;
}

// Function to find the maximum minimum distance
int maxMinDistance(vector<int>& positions, int cows) {
    sort(positions.begin(), positions.end());  // Sort the pole positions
    
    int low = 1;  // Minimum possible distance
    int high = positions.back() - positions.front();  // Maximum possible distance
    int result = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Midpoint to avoid overflow
        if (canPlaceCows(positions, cows, mid)) {
            result = mid;  // Update result with the current maximum minimum distance
            low = mid + 1;  // Try for a larger distance
        } else {
            high = mid - 1;  // Try for a smaller distance
        }
    }
    return result;
}

int main() {
	freopen("filename.inp", "r", stdin);
    freopen("filename.out", "w", stdout);
    int N, C;
    cin >> N >> C;
    
    vector<int> positions(N);
    for (int i = 0; i < N; ++i) {
        cin >> positions[i];
    }
    
    cout << maxMinDistance(positions, C) << endl;
    return 0;
}


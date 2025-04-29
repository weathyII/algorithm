#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;

        long long validSubarrays = 0;

        // Check every possible pair of indices i, j
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j >= i + 2) {
                    bool isValid = true;

                    // Check if the 3 points (i1, i2, j) form a collinear segment
                    for (int i1 = i; i1 < j; i1++) {
                        for (int i2 = i1 + 1; i2 < j; i2++) {
                            long long d1 = abs(a[i1] - a[j]) + abs(i1 - j);  // Distance between i1 and j
                            long long d2 = abs(a[i1] - a[i2]) + abs(i1 - i2);  // Distance between i1 and i2
                            long long d3 = abs(a[i2] - a[j]) + abs(i2 - j);  // Distance between i2 and j

                            // If points i1, i2, and j are collinear, break
                            if (d1 == d2 + d3) {
                                isValid = false;
                               
                            }
                        }
                    }

                    // If the subarray is valid, increment the count
                    if (!isValid) break;
                }
                validSubarrays++;
            }
        }

        cout << validSubarrays << endl;
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length(), ans = 0;

        for (int d = 1; d <= n / 2; ++d) {
            int cnt = 0;
            for (int i = 0; i < n - d; ++i) {
                cnt += (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?');
                if (i - d >= 0) {
                    cnt -= (s[i - d] == s[i] || s[i - d] == '?' || s[i] == '?');
                }
                if (i - d >= -1 && cnt == d) {
                    ans = max(ans, 2 * d);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

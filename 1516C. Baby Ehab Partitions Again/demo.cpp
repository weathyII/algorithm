#include "bits/stdc++.h"
using namespace std;
int n;
bool bad(vector<int> &v)
{
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum % 2)
    {
        return false;
    }
    bitset<200005> b;
    b[0] = 1;
    for (int i : v)
        b |= (b << i);
    return b[sum / 2];
}
int main()
{

    cin >> n;
    vector<int> v(n);
    for (size_t i = 0; i < n; i++)
    {
        /* code */
        cin >> v[i];
    }
    if (bad(v))
    {
        pair<int, int> mn(20, 0);
        for (size_t i = 0; i < n; i++)
        {
            /* code */
            mn = min(mn, {__builtin_ctz(v[i]), i + 1});
        }
        cout << 1 << endl;
        cout << mn.second;
    }
    else
    {
        cout << 0;
        return 0;
    }
}
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int main()
{
    ll l, r;
    cin >> l >> r;
    ll p = l ^ r;
    ll x = 1;
    while (x <= p)
    {
        x = x << 1;
    }
    cout << x - 1 << endl;
    return 0;
}
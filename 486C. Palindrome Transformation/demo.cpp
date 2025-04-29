#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <stack>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
//#include <bits/stdc++.h>
//#define LOACL
#define space " "
using namespace std;
//typedef long long LL;
typedef __int64 Int;
typedef pair<int, int> paii;
const int INF = 0x3f3f3f3f;
const double ESP = 1e-5;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
char str[MAXN];
int main() {
    int n, p;
    while (scanf("%d%d", &n, &p) != EOF) {
        scanf("%s", str + 1);
        int psum = 0, las, fir;
        bool flag = true;
        //把p换到左边
        if(p > n/2)  p = n + 1 - p;
        for (int i = 1; i <= n/2; i++) {
            int op = abs(str[i] - str[n + 1 - i]);
            if (op) {
                if (flag) {
                    fir = i; flag = false;
                }
                psum += min(op, 26 - op);
                las = i;
            }
        }
        if (psum == 0) printf("0\n");
        else if (fir >= p) printf("%d\n", las - p + psum);
        else if (las <= p) printf("%d\n", p - fir + psum);
        else{
            printf("%d\n", min(2*(p - fir) + las - p, 2*(las - p) + p - fir) + psum);
        }
    }
    return 0;
}
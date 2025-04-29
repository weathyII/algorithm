#include <bits/stdc++.h>
using namespace std;
int get(int n) {
	int ans = 0;
	while (n % 2 == 0) n /= 2, ans ++;
	
	for (int i = 3; i <= n / i; i += 2) {
		if (n % i ==0) {
			while (n % i == 0) n /= i, ans ++;
		}
	}	 
	if (n > 1) ans ++;
	return ans;
}
void solve () {
	int a, b, k;
	cin >> a >> b >> k;
	if (k == 1)  {//先考虑特例
		if ((a % b == 0 || b % a == 0) && a != b) puts ("YES");
		else puts ("NO");
	}
	else {
		int ans = get (a) +  get(b);
		if (ans >= k) puts ("YES");
		else puts ("NO");
	}
	
}
int main () {
	int t;
	cin >> t;
	while (t --) {
		solve ();
 	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5+5;
int n;
int a[N];
int num[N*2];
 
void solve(){
	cin>>n;
	for(int i=0;i<=n*2;i++){
		num[i]=0;
	}
	num[0]++;
	int ans=n*(n+1)/2;
	int pre=0;
 
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		pre^=x;
		for(int j=0;(pre^(j*j))<=2*n;j++){
			ans-=num[pre^(j*j)];
		}
		num[pre]++;
	}
 
	cout<<ans<<"\n";
	
}
 
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t=1;cin>>t;
	
	while(t--){
		solve();
	}
 
	return 0;
}
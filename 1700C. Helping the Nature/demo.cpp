#include<bits/stdc++.h>
using namespace std;
//从左往右操作，每次操作一对，让两数中大的变成和小的相同的数。
//（注意，大的数和他左边或者右边所有的数都变化了，可以用“懒标记”等到达位置再变化
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         vector<long long> a(n);
//         for(int i=0;i<n;i++)
//             cin>>a[i];
        
//         int ans=0;
//         int right=0;
//         for(int i=1;i<n;i++){
//             a[i]+=right;
//             int dif=abs(a[i]-a[i-1]);
//             ans+=dif;
//             if(a[i]>a[i-1])
//                 right-=dif;
//             a[i]=min(a[i],a[i-1]);
//         }
//         ans+=abs(a[n-1]);
//         cout<<ans<<endl;

//     }
//     return 0;
// }



#include <iostream>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll T,a[N],b[N];
void slove(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=a[i]-a[i-1];
	ll ans=0;
	for(int i=2;i<=n;i++){
		if(b[i]>0)ans+=b[i];
		else if(b[i]<0){
			ans-=b[i];
			b[1]+=b[i];
		}
	}
	cout<<ans+abs(b[1])<<endl;
}
int main(){
	cin>>T;while(T--)
	slove();
	return 0;
}

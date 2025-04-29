#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    if(n==1) cout<<0<<endl;
    if(n<=k) cout<<1<<endl;
    long long l=2,r=k,ans=-1,out=k*(k+1)/2-k;
    while(l<=r){
        long long mid=(l+r)/2;
        long long temp=out-(mid-1)*mid/2+mid;
        if(temp>=n){
            ans=k-mid+1;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    unordered_map<int,int> cnt;
    int mx=0,mxcnt=0;
    for(int i=0,temp;i<n;i++){
        cin>>temp;
        cnt[temp]++;
        mx=max(mx,cnt[temp]);
    }
    for(auto i:cnt){
        if(i.second==mx){
            mxcnt++;
        }
    }
    long long low=0,high=n-1,mid,ans=0;
    while(low<high){
        mid=low+((high-low)>>1);
        long long req=mxcnt+(mx-1)*(mid+1);//mx-1 times we need to add mid+1 elements to make all elements equal to mx
        if(req<=n){
            ans=max(ans,mid);
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
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
    
    cout<<mxcnt-1+(n-mxcnt*mx)/(mx-1)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
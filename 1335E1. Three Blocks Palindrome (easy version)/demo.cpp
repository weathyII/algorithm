#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int>> cnt(26,vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            cnt[j][i+1]=cnt[j][i];
        }
        cnt[a[i]-1][i+1]++;
    }
    int ans=0;
    for(int i=0;i<26;i++){
        ans=max(ans,cnt[i][n-1]);
    }
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            int cntin=0,cntout=0;
            for(int i=0;i<26;i++){
                cntin=max(cntin,cnt[i][r+1]-cnt[i][l]);
                cntout=max(cntout,min(cnt[i][l],cnt[i][n]-cnt[i][r+1])*2);
            }
            ans=max(ans,cntin+cntout);
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
    return 0;
}
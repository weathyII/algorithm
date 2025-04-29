#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    vector<int> a(n);
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    vector<int> b(n);
    for(int i=1;i<n;i++){
        cin>>b[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(2,1e9));
    
    dp[1][0]=0;
    dp[1][1]=c;
    cout<<0<<" ";
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][0]+a[i-1],dp[i-1][1]+a[i-1]);
        dp[i][1]=min(dp[i-1][0]+b[i-1]+c,dp[i-1][1]+b[i-1]);
        cout<<min(dp[i][0],dp[i][1])<<" ";

    }
    return 0;

}
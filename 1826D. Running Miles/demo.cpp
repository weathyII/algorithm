#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<long long> a(n+1), l(n+1), r(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            l[i]=a[i]+i;
            r[i]=a[i]-i;
        }
        for(int i=2;i<=n;i++) l[i]=max(l[i],l[i-1]);
        for(int i=n-1;i>=1;i--) r[i]=max(r[i],r[i+1]);
        long long ans=0;
        for(int i=2;i<n;i++){
            ans=max(ans,a[i]+l[i-1]+r[i+1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int t,nr,ng,nb;
long long ans;
long long sqr(long long x)
{
    return x*x;
}
void solve(vector<long long> r,vector<long long> g,vector<long long> b){
    for(auto x:r){
        auto y=lower_bound(g.begin(),g.end(),x);
        auto z=upper_bound(b.begin(),b.end(),x);
        if(y!=g.end()&&z!=b.begin()){
            z--;
            ans=min(ans,sqr(x-*y)+sqr(*y-*z)+sqr(*z-x));
        }
    }

}
int main()
{

    for(cin>>t;t;t--){
        cin>>nr>>ng>>nb;
        vector<long long> r(nr),g(ng),b(nb);
        for(int i=0;i<nr;i++) cin>>r[i];
        for(int i=0;i<ng;i++) cin>>g[i];
        for(int i=0;i<nb;i++) cin>>b[i];
        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(),b.end());
        ans=9e18;
        solve(r,g,b);
        solve(r,b,g);
        solve(g,r,b);
        solve(g,b,r);
        solve(b,r,g);
        solve(b,g,r);
        cout<<ans<<endl;
    }
    return 0;
}
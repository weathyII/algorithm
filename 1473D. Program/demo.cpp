#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int> sufmin(1,0),sufmax(1.0);
        for(int i=n-1;i>=0;i--){
            int d=s[i]=='+'?1:-1;
            sufmin.push_back(min(0,sufmin.back()+d));
            sufmax.push_back(max(0,sufmax.back()+d));
        }
        reverse(sufmin.begin(),sufmin.end());
        reverse(sufmax.begin(),sufmax.end());
        vector<int> premin(1,0),premax(1,0),pre(1,0);
        for(int i=0;i<n;i++){
            int d=s[i]=='+'?1:-1;
            pre.push_back(pre.back()+d);
            premin.push_back(min(premin.back(),pre.back()));
            premax.push_back(max(premax.back(),pre.back()));
        }
        for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            l--;
            cout<<max(premax[l],sufmax[r]+pre[l])-min(premin[l],sufmin[r]+pre[l])+1<<endl;
        }
        
        
        
    }
}
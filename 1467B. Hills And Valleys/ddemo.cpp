#include <bits/stdc++.h>
using namespace std;
int isValley(int i, vector<int> &v){
    return i>0&&i<v.size()-1&&v[i]<v[i-1] && v[i]<v[i+1];
}
int isHill(int i, vector<int> &v){
    return i>0&&i<v.size()-1&&v[i]>v[i-1] && v[i]>v[i+1];
}
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        /* code */
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        int is[n]={};
        int s=0;
        for (int i = 1; i < n-1; i++)
        {
            if (isValley(i,v)||isHill(i,v))
            {
                is[i]=1;
                s++;
            }
        }
        int ans=s;
        for(int i=1;i<n-1;i++){
            int temp=v[i];
            v[i]=v[i+1];
            ans=min(ans,s-is[i-1]-is[i]-is[i+1]+isValley(i-1,v)+isHill(i-1,v)+isValley(i,v)+isHill(i,v)+isValley(i+1,v)+isHill(i+1,v));
            v[i]=v[i-1];
            ans=min(ans,s-is[i-1]-is[i]-is[i+1]+isValley(i-1,v)+isHill(i-1,v)+isValley(i,v)+isHill(i,v)+isValley(i+1,v)+isHill(i+1,v));
            v[i]=temp;
        }
        cout<<ans<<endl;
    }
    
}
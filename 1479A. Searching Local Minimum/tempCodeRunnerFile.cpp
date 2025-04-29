#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n=0;
ll arr[100008];
void query(ll x){
    //cout<<"x="<<x<<endl;
    if(x>=1 && x<=n &&arr[x]==0){
        cout<<"? "<<x<<endl;
        fflush(stdout);
        cin>>arr[x];
    }
}
int main()
{
    // ll t;
    // cin>>t;
    // while(t--){
        cin>>n;
        // cout<<endl;
        ll i=1,j=n,m;
        for(int i=1;i<=n;i++)arr[i]=0;
        arr[0]=arr[n+1]=INT_MAX;
        while(i<=j)
        {
            //cout<<"i="<<i<<" j="<<j<<endl;
            m=(i+j)/2;
            query(m);
            query(m-1);
            query(m+1);
            //cout<<"m="<<m<<" arr[m]="<<arr[m]<<endl;
            if(arr[m]<arr[m-1] && arr[m]<arr[m+1]){
                break;
            }
            else if(arr[m]>arr[m-1]){
                j=m-1;
            }
            else{
                i=m+1;
            }
        }
        cout<<"! "<<m<<endl;
        fflush(stdout);
    // }

    return 0;
}
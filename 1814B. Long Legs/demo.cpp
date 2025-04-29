#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    long long a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        long long ans=a+b;
        for(int i=1;i<1e5;i++){
            ans=min(ans,(a+i-1)/i+(b+i-1)/i+i-1);

        }
        cout<<ans<<endl;
    }
}
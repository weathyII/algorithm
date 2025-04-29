#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    int t;
    cin >> t;
    while(t--){
        cin>>a>>b>>c;
        if(a+1!=c){cout<<-1<<endl;continue;}
        if(a+b+c==1){cout<<0<<endl;continue;}
        int curr=1,next=0,res=1;
        for(int i=0;i<a+b;i++){
            if(curr==0){
                swap(curr,next);
                res++;
            }
            curr--;
            next++;
            if(i<a) next++;
        }
        cout<<res<<endl;
    }
}
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
    long long i,n,x,y;
    cin>>n;
    while(n--){
        cin>>x>>y;
        for(i=1;(x|i)<=y;i<<=1){
            x|=i;
        }
        cout<<x<<endl;
    } 
}
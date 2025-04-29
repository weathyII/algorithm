#include<bits/stdc++.h>
using namespace std;
string smallest(string a){
    if(a.length()%2==1){
        return a;
    }
    string a1=smallest(a.substr(0,a.length()/2));
    string a2=smallest(a.substr(a.length()/2,a.length()/2));
    if(a1<a2){
        return a1+a2;

    }
    else{
        return a2+a1;
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    if(smallest(a)==smallest(b)){
        cout<<"YES"<<endl;
        return 0;
    }
    else{
        cout<<"NO"<<endl;
        return 0;
    }

    
}
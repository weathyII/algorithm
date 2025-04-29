/*** keep hungry and calm CoolGuang!  ***/
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<iostream>
#define debug(x) cout<<#x<<":"<<x<<endl;
#define dl(x) printf("%lld\n",x);
#define di(x) printf("%d\n",x);
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll INF= 1e18+7;
const ll maxn = 1e6+700;
const int M = 1e6+8;
const ll mod= 998244353;
const double eps = 1e-9;
const double PI = acos(-1);
template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}
ll n,m,p;
int cnt = 0;
int prime[maxn],vis[maxn];
int isd[maxn];
ll num[maxn]; 
pair<int,int>res[maxn];
multiset<int>s;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        read(n);
        s.clear();
        for(int i=1;i<=2*n;i++){
            read(num[i]);

        }
        sort(num+1,num+1+2*n);
        int cnt = 0;
        for(int i=1;i<=2*n-1;i++){
            s.clear();
            for(int k=1;k<=2*n;k++) s.insert(num[k]);
            s.erase(s.find(num[i]));
            s.erase(s.find(num[2*n]));
            ll x = num[2*n];
            cnt = 0;
            res[++cnt] = {num[i],num[2*n]};
            for(int k=1;k<=n-1;k++){
                int temp = *prev(s.end());
                s.erase(s.find(temp));
                if(s.find(x-temp)!=s.end()){
                    s.erase(s.find(x-temp));
                    res[++cnt] = {temp,x-temp};
                    x = temp;
                }
                else break;
            }
            if(cnt == n) break;
        }
        if(cnt == n){  
            puts("YES");
            printf("%d\n",res[1].first +  res[1].second);
            for(int i=1;i<=cnt;i++)
                printf("%d %d\n",res[i].first,res[i].second);
        }else puts("NO");
    }
    return 0;
}



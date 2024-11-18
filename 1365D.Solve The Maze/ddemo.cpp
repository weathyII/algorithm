#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

char mp[55][55];
int n,m,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

bool prim(int x,int y)
{
    return x>0&&y>0&&x<=n&&y<=m;
}

void solve()
{
    int cnt=0,cnt2=0;
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>mp[i][j];
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]=='B') //如果找到一个坏人，就在它周围尝试设置墙
            {
                for(int k=0;k<4;k++)
                {
                    int px=dx[k]+i,py=dy[k]+j;
                    if(prim(px,py))
                    {
                        if(mp[px][py]=='.')
                            mp[px][py]='#';
                        else if(mp[px][py]=='G') //坏人周围有好人的情况
                        {
                            cout<<"No\n";
                            return;
                        }
                    }
                }
            }
            else if(mp[i][j]=='G') //如果是好人，记录数量
                cnt++;
        }
    }
    
    if(mp[n][m]=='#') //坏人周围建完墙后如果把(n,m)也设置成墙了
    {
        if(cnt==0) //可行方案中一定不能存在好人
            cout<<"Yes\n";
        else
            cout<<"No\n";
        return;
    }
    
    queue<P> q;
    q.push(P(n,m)); //从(n,m)开始搜索，记录能搜索到的好人数量
    mp[n][m]='#';
    while(!q.empty())
    {
        P pd=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int px=dx[i]+pd.first,py=dy[i]+pd.second;
            if(prim(px,py)&&mp[px][py]!='#')
            {
                if(mp[px][py]=='G') //记录能搜索到的好人数量
                    cnt2++;
                q.push(P(px,py));
                mp[px][py]='#';
            }
        }
    }
    
    if(cnt==cnt2)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--)
        solve();
    return 0;
}
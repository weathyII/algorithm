#include "bits/stdc++.h"

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long p, f;
        cin >> p >> f;
        long long cnts, cntw;
        cin >> cnts >> cntw;
        long long s, w;
        cin >> s >> w;
        long long ans = 0;
        if (s > w)
        {
            swap(s, w);
            swap(cnts, cntw);
        }
        for (int i = 0; i <= cnts; i++)
        {
            long long temp=0;
            if (i*s<=p)
            {
                temp+=i;
                temp+=(p-i*s)/w;
            }
            long long temp1;
            if(!temp)
            temp1=0;
            else temp1=i;

            long long temp2=min(f/s,cnts-temp1);
            temp+=temp2;
            temp+=min((f-temp2*s)/w,cntw-(p-i*s)/w);
            ans=max(ans,temp);

        }
        cout << ans << endl;
    }
}
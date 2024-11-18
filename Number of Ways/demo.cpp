#include<iostream>
#include<vector>
using namespace std;
int countWays(vector<long long> arr)
{
    int n=arr.size();
    int count=0;
    if (n<3)
    {
        return 0;
    }
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            if(arr[i]==(arr[j]-arr[i])&&arr[i]==(arr[n-1]-arr[j]))
            {
                count++;
            }
        }
    }
    return count;

    
    
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<long long> sumarr(n,0);
    sumarr[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        sumarr[i]=sumarr[i-1]+arr[i];
    }
    cout<<countWays(sumarr);
    
}
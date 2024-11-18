#include<iostream>
#include<vector>
using namespace std;

string findLongestSubstring(const string& s){
    int n=s.size();
    //pi[i]表示s[0...i]的最长前缀后缀相等的长度,同时也是最长前缀字符串的后一个字符的位置
    vector<int> pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j]){
            j=pi[j-1];
        }
        if(s[i]==s[j]){
            j++;
        }
        pi[i]=j;
    }
    int length_of_t=pi[n-1];
    while (length_of_t > 0) {
        for (int i = 0; i < n - 1; i++) {
            if (pi[i] == length_of_t) {
                return s.substr(0, length_of_t);
            }
        }
        length_of_t = pi[length_of_t - 1];
    }

    return "Just a legend";
}

int main(){
    string s;
    cin>>s;
    cout<<findLongestSubstring(s)<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    set<string> st;
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    for (auto &rs : a)
    {
        string s = rs;
        reverse(rs.begin(), rs.end());
        if (rs == s)
        {
            cout << "YES" << endl;
            return;
        }
        else
        {           
            if (s.size() == 2)
            {
                string s1 = "";
                s1 += s[1];
                s1 += s[0];
                if (st.find(s1) != st.end())
                {
                    cout << "YES" << endl;
                    return;
                }
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    string t = s1;
                    t += ch;
                    if (st.find(t) != st.end())
                    {
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
            if (s.size() == 3)
            {
                string s1 = "";
                s1 += s[2];
                s1 += s[1];
                if (st.find(s1) != st.end())
                {
                    cout << "YES" << endl;
                    return;
                }
                s1 += s[0];
                if (st.find(s1) != st.end())
                {
                    cout << "YES" << endl;
                    return;
                }
            }
            st.insert(s);
        }
        
    }
    cout << "NO" << endl;
}
int main()
{

    int t, n;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
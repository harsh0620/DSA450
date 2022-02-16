#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void remove(string st, string &ans)
    {
        if (st.size() == 0)
        {
            return;
        }
        remove(st.substr(1), ans);

        if (ans.empty())
        {
            ans += st.front();
        }
        else if (ans.back() != st.front())
        {
            ans += st.front();
        }
    }

    string removeConsecutiveCharacter(string S)
    {
        // code here.
        string ans;
        remove(S, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.removeConsecutiveCharacter(s) << endl;
    }
}

// } Driver Code Ends
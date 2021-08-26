#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string s)
    {
        // Code here
        vector<int> f(26, 0);
        vector<char> v;
        string ans;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (f[s[i] - 'a'] == 0)
            {
                v.push_back(s[i]);
            }
            f[s[i] - 'a']++;

            int fi = 0;
            int m = v.size();
            for (int j = 0; j < m; j++)
            {
                if (f[(v[j] - 'a')] == 1)
                {
                    ans += v[j];
                    fi = 1;
                    break;
                }
            }
            if (fi == 0)
            {
                ans += "#";
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends
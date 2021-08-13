#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int lcs(string a, string b, int n, int m)
    {
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i - 1] == b[j - 1] && i - 1 != j - 1)
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    int LongestRepeatingSubsequence(string str)
    {
        string a = str;
        string b = str;
        int n = a.length();
        int m = b.length();
        return lcs(a, b, n, m);
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.LongestRepeatingSubsequence(s);

        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int dp[100][100];
class Solution
{
public:
    int countFriendsPairings(int n)
    {
        // code here
        long long dp[n + 1];
        long long mod = 1e9 + 7;
        for (int i = 0; i <= n; i++)
        {
            if (i <= 2)
            {
                dp[i] = i;
            }
            else
            {
                (dp[i] = dp[i - 1] % mod + (i - 1) * dp[i - 2]) %= mod;
            }
        }
        return dp[n] % mod;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n) << endl;
    }
    return 0;
}
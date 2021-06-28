#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;

class Solution
{
public:
    int catalanNum(int n)
    {
        int dp[n + 1];
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
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
        cout << ob.catalanNum(n) << endl;
    }
    return 0;
}
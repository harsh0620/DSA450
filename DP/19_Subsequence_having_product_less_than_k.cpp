#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int dp[200][200][200];
class Solution
{
public:
    int numOfSubsHavingK(vector<int> &a, int k)
    {
        int n = a.size();
        int dp[k + 1][n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i][j - 1];
                if (a[j - 1] <= i && a[j - 1] > 0)
                {
                    dp[i][j] += dp[i / a[j - 1]][j - 1] + 1;
                }
            }
        }
        return dp[k][n];
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
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int k;
        cin >> k;

        Solution ob;
        cout << ob.numOfSubsHavingK(a, k) << endl;
    }
    return 0;
}
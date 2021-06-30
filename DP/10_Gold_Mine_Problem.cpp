#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int dp[100][100];

class Solution
{
public:
    int goldMine(int gold[][MAX], int m, int n)
    {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));
        for (int col = n - 1; col >= 0; col--)
        {
            for (int row = 0; row < m; row++)
            {
                int right = (col == n - 1) ? 0 : dp[row][col + 1];
                int right_up = (col == n - 1 || row == 0) ? 0 : dp[row - 1][col + 1];
                int right_down = (col == n - 1 || row == m - 1) ? 0 : dp[row + 1][col + 1];

                dp[row][col] += gold[row][col] + max(right, max(right_down, right_up));
            }
        }
        int ans = dp[0][0];
        for (int i = 1; i < m; i++)
        {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int gold[MAX][MAX];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> gold[i][j];
            }
        }
        Solution ob;
        cout << ob.goldMine(gold, m, n) << endl;
    }
    return 0;
}
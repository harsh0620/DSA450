#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int dp[200][200][200];
class Solution
{
public:
    int numSumWithout3_Consecutive(vector<int> &a, int n)
    {
        int sum[n];

        if (n >= 1)
        {
            sum[0] = a[0];
        }
        if (n >= 2)
        {
            sum[1] = a[0] + a[1];
        }
        if (n >= 3)
        {
            sum[2] = max(sum[1], max(a[0] + a[2], a[1] + a[2]));
        }
        for (int i = 3; i < n; i++)
        {
            sum[i] = max(sum[i - 3] + a[i] + a[i - 1], max(sum[i - 1], a[i] + sum[i - 2]));
        }
        return sum[n - 1];
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

        Solution ob;
        cout << ob.numSumWithout3_Consecutive(a, n) << endl;
    }
    return 0;
}
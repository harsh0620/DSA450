#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int kmin = 0, kmax = 0;
        int mini = prices[0];

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < mini)
            {
                mini = prices[i];
                kmin = i;
            }
        }
        int maxi = 0;
        for (int i = kmin + 1; i < prices.size(); i++)
        {
            if (prices[i] > maxi)
            {
                maxi = prices[i];
                kmax = i;
            }
        }
        if (kmin > kmax)
        {
            return 0;
        }
        else
        {
            return maxi - mini;
        }
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        cout << ob.maxProfit(v) << endl;
    }
    return 0;
}
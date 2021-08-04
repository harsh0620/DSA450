#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int maxProfit(int price[], int n)
    {
        int profit[n] = {0};

        int max_price = price[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (price[i] > max_price)
            {
                max_price = price[i];
            }
            profit[i] = max(profit[i + 1], max_price - price[i]);
        }
        int min_price = price[0];
        for (int i = 1; i < n; i++)
        {
            if (price[i] < min_price)
            {
                min_price = price[i];
            }
            profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
        }
        return profit[n - 1];
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
        int v[n];

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        cout << ob.maxProfit(v, n);

        cout << endl;
    }
    return 0;
}

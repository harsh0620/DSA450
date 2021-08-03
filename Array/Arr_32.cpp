#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int minSwap(int *arr, int n, int k)
    {
        // Complet the function
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                cnt++;
            }
        }
        int bad = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (arr[i] > k)
            {
                bad++;
            }
        }
        int ans = bad;
        for (int i = 0, j = cnt; j < n; j++, i++)
        {
            if (arr[i] > k)
            {
                bad--;
            }
            if (arr[j] > k)
            {
                bad++;
            }
            ans = min(ans, bad);
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
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minSwap(a, n, m);
        cout << endl;
    }
    return 0;
}

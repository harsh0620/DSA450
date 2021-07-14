#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        // code here
        int cnt = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            cnt += mp[k - arr[i]];

            if (k - arr[i] == arr[i])
            {
                cnt--;
            }
        }
        return cnt / 2;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.getPairsCount(a, n, k) << endl;
    }
    return 0;
}
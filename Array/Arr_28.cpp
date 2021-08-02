#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int trappingWater(int arr[], int n)
    {
        // Code here
        int left[n];
        int right[n];

        left[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], arr[i]);
        }
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], arr[i]);
        }
        int water = 0;
        for (int i = 0; i < n; i++)
        {
            water += min(left[i], right[i]) - arr[i];
        }
        return water;
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
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        cout << ob.trappingWater(a, n);
        cout << endl;
    }
    return 0;
}

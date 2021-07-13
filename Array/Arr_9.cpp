#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        if (n == 1)
            return 0;

        sort(arr, arr + n);

        int diff = arr[n - 1] - arr[0];

        int minimum = arr[0] + k;
        int maximum = arr[n - 1] - k;
        int temp = 0;

        if (minimum > maximum)
        {
            temp = minimum;
            minimum = maximum;
            maximum = temp;
        }
        for (int i = 1; i < n - 1; i++)
        {
            int difference = arr[i] - k;
            int sum = arr[i] + k;
            if (difference >= minimum || sum <= maximum)
                continue;

            if (maximum - difference <= sum - minimum)
                minimum = difference;
            else
                maximum = sum;
        }
        return min(diff, maximum - minimum);
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
        cout << ob.getMinDiff(a, n, k) << " ";
    }
    return 0;
}
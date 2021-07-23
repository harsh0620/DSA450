#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> map;

        // Maintains sum of elements so far
        int curr_sum = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            // add current element to curr_sum
            curr_sum = curr_sum + arr[i];

            // if curr_sum is equal to target sum
            // we found a subarray starting from index 0
            // and ending at index i
            if (curr_sum == sum)
            {
                return true;
            }

            // If curr_sum - sum already exists in map
            // we have found a subarray with target sum
            if (map.find(curr_sum - sum) != map.end())
            {
                return true;
            }

            map[curr_sum] = i;
        }

        return false;
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
        cout << ob.subArrayExists(a, n);
        cout << endl;
    }
    return 0;
}
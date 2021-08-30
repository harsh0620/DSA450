#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int indexValue(vector<int> &nums, int target)
    {

        int first = 0;
        int n = nums.size();
        int last = n - 1;

        while (first <= last)
        {
            if (nums[first] == target)
            {
                return first;
            }
            if (nums[last] == target)
            {
                return last;
            }
            last--;
            first++;
        }
        return -1;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int target;
        cin >> target;
        Solution ob;
        cout << ob.indexValue(a, target);
    }
    return 0;
}
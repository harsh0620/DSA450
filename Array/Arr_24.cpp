#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    vector<int> majorityElement2(vector<int> &nums)
    {
        map<int, int> neg, pos;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                int p = abs(nums[i]);
                neg[p]++;
            }
            else
            {
                pos[nums[i]]++;
            }
        }
        vector<int> ans;
        for (auto it : neg)
        {
            if (it.second > n / 3)
            {
                ans.push_back(-1 * (it.first));
            }
        }
        for (auto it : pos)
        {
            if (it.second > n / 3)
            {
                ans.push_back(it.first);
            }
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.majorityElement2(v);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

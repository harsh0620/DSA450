#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        if (intervals.size() == 0)
        {
            return ans;
        }
        vector<int> temp;
        sort(intervals.begin(), intervals.end());
        temp = intervals[0];
        for (auto it : intervals)
        {
            if (it[0] <= temp[1])
            {
                temp[1] = max(temp[1], it[1]);
            }
            else
            {
                ans.push_back(temp);
                temp = it;
            }
        }
        ans.push_back(temp);
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
        vector<vector<int>> v(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            int a, b;
            cin >> a >> b;
            temp.push_back(a);
            temp.push_back(b);
            v.push_back(temp);
        }
        Solution ob;
        vector<vector<int>> ans = ob.mergeIntervals(v);

        for (auto x : ans)
        {
            cout << x[0] << " " << x[1] << endl;
        }
    }
    return 0;
}
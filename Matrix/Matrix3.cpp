#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int median1(vector<vector<int>> &matrix, int r, int c)
    {

        vector<int> ans;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans[(r * c) / 2];
    }
    int median2(vector<vector<int>> &m, int r, int c)
    {

        int mini = INT_MAX, maxi = INT_MIN;

        for (int i = 0; i < r; i++)
        {
            mini = min(mini, m[i][0]);
            maxi = max(maxi, m[i][c - 1]);
        }

        int point = (r * c + 1) / 2;

        while (mini < maxi)
        {
            int mid = mini + (maxi - mini) / 2;

            int place = 0;

            for (int i = 0; i < r; i++)
            {
                place += upper_bound(m[i].begin(), m[i].end(), mid) - m[i].begin();
            }
            if (place < point)
            {
                mini = mid + 1;
            }
            else
            {
                maxi = mid;
            }
        }
        return mini;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> v(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> v[i][j];
            }
        }
        Solution ob;
        cout << ob.median2(v, r, c);
        cout << endl;
    }
    return 0;
}

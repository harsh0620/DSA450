#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int findMaxValue(vector<vector<int>> m)
    {
        int maxValue = INT_MIN;
        int n = m.size();
        int maxv = m[n - 1][n - 1];
        vector<vector<int>> maxa(n, vector<int>(n, 0));
        maxa[n - 1][n - 1] = m[n - 1][n - 1];

        for (int j = n - 2; j >= 0; j--)
        {
            if (m[n - 1][j] > maxv)
            {
                maxv = m[n - 1][j];
            }
            maxa[n - 1][j] = maxv;
        }
        maxv = m[n - 1][n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (m[i][n - 2] > maxv)
            {
                maxv = m[i][n - 2];
            }
            maxa[i][n - 2] = maxv;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (maxa[i + 1][j + 1] - m[i][j] > maxValue)
                {
                    maxValue = maxa[i + 1][j + 1] - m[i][j];
                }
                maxa[i][j] = max(m[i][j], max(maxa[i][j + 1], maxa[i + 1][j]));
            }
        }
        return maxValue;
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
        cout << ob.findMaxValue(v);
        cout << endl;
    }
    return 0;
}
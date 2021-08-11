#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> mat, int n, int k)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                v.push_back(mat[i][j]);
            }
        }
        sort(v.begin(), v.end());
        return v[k - 1];
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
        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(v, r, k);

        cout << endl;
    }
    return 0;
}

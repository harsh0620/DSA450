#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix[0][0] > target)
        {
            return false;
        }
        int prev = -1;
        int next = 0;
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] > target)
            {
                prev = i - 1;
                break;
            }
        }
        if (prev == -1)
        {
            prev = n - 1;
        }
        vector<int> temp = matrix[prev];
        if (binary_search(temp.begin(), temp.end(), target))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        int x;
        cin >> x;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        Solution ob;
        cout << ob.searchMatrix(v, x);

        cout << endl;
    }
    return 0;
}

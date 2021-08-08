#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        // code here
        int pos = -1;
        int prevCnt = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = m - count(arr[i].begin(), arr[i].end(), 0);
            if (cnt > prevCnt)
            {
                pos = i;
                prevCnt = cnt;
            }
        }
        return pos;
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
        cout << ob.rowWithMax1s(v, r, c);
        cout << endl;
    }
    return 0;
}

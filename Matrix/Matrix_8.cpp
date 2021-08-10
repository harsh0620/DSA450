#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    void rotate90Clockwise(vector<vector<int>> &a)
    {
        int n = a.size();
        int N = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(a[i][j], a[j][i]);
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     reverse(a[i].begin(), a[i].end());
        // }Way 1

        //Way2
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N / 2; ++j)
            {
                int temp = a[i][j];
                a[i][j] = a[i][N - j - 1];
                a[i][N - j - 1] = temp;
            }
        }
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
        ob.rotate90Clockwise(v);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
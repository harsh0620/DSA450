#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
    {
        // code here
        int n = Mat.size();
        int m = Mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<int> v;
        for (int i = 0; i < Mat.size(); i++)
        {
            for (int j = 0; j < Mat[i].size(); j++)
            {
                v.push_back(Mat[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int k = 0;
        for (int i = 0; i < Mat.size(); i++)
        {
            for (int j = 0; j < Mat[i].size(); j++)
            {
                ans[i][j] = v[k];
                k++;
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
        vector<vector<int>> res = ob.sortedMatrix(r, v);
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
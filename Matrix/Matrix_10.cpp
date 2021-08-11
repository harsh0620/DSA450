#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    void printCommonElements(vector<vector<int>> mat)
    {
        unordered_map<int, int> mp;
        int n = mat.size();
        for (int j = 0; j < n; j++)
            mp[mat[0][j]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (mp[mat[i][j]] == i)
                {

                    mp[mat[i][j]] = i + 1;

                    if (i == n - 1 && mp[mat[i][j]] == n)
                        cout << mat[i][j] << " ";
                }
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
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }

        Solution ob;
        ob.printCommonElements(v);

        cout << endl;
    }
    return 0;
}
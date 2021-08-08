#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> v, int r, int c)
    {
        bool r1 = true, c1 = false, r2 = false, c2 = false;

        int i = 0, j = 0;
        int cnt = 0;
        vector<int> ans;
        vector<vector<int>> freq(r, vector<int>(c, 0));
        while (cnt < r * c)
        {
            if (r1 == true)
            {
                ans.push_back(v[i][j]);
                freq[i][j] = 1;
                if (j + 1 == c || freq[i][j + 1] == 1)
                {
                    j = j;
                    i++;
                    r1 = false;
                    c1 = true;
                    r2 = false;
                    c2 = false;
                }
                else
                {
                    j++;
                }
            }
            else if (c1 == true)
            {
                ans.push_back(v[i][j]);
                freq[i][j] = 1;
                if (i + 1 == r || freq[i + 1][j] == 1)
                {
                    i = i;
                    j--;
                    r1 = false;
                    c1 = false;
                    r2 = true;
                    c2 = false;
                }
                else
                {
                    i++;
                }
            }
            else if (r2 == true)
            {
                ans.push_back(v[i][j]);
                freq[i][j] = 1;
                if (j - 1 == -1 || freq[i][j - 1] == 1)
                {
                    j = j;
                    i--;
                    r1 = false;
                    c1 = false;
                    r2 = false;
                    c2 = true;
                }
                else
                {
                    j--;
                }
            }
            else if (c2 == true)
            {
                ans.push_back(v[i][j]);
                freq[i][j] = 1;
                if (i - 1 == -1 || freq[i - 1][j] == 1)
                {
                    j = j;
                    j++;
                    r1 = true;
                    c1 = false;
                    r2 = false;
                    c2 = false;
                }
                else
                {
                    i--;
                }
            }
            cnt++;
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
        vector<int> result = ob.spirallyTraverse(v, r, c);
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

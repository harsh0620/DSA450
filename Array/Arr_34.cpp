#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int find_median(vector<int> v)
    {
        sort(v.begin(), v.end());
        if (v.size() % 2 == 0)
        {
            return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
        }
        else
        {
            return v[v.size() / 2];
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
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        cout << ob.find_median(v);
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    string isSubset(int a1[], int a2[], int n, int m)
    {
        sort(a1, a1 + n);
        sort(a2, a2 + m);
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if (binary_search(a1, a1 + n, a2[i]))
            {
                cnt++;
            }
            else
            {
                return "No";
            }
        }
        if (cnt == m)
        {
            return "Yes";
        }
        else
        {
            return "No";
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
        int a[n];
        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isSubset(a, b, n, m);
        cout << endl;
    }
    return 0;
}

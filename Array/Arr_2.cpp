#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    void minMax(int a[], int n)
    {
        int i = 0;
        if (n % 2 == 0)
        {
            mini = min(a[0], a[1]);
            maxi = max(a[0], a[1]);
            i = 2;
        }
        else
        {
            mini = a[0];
            maxi = a[0];
            i = 1;
        }
        while (i < n - 1)
        {
            if (a[i] > a[i + 1])
            {
                mini = min(mini, a[i + 1]);
                maxi = max(a[i], maxi);
            }
            else
            {
                mini = min(a[i], mini);
                maxi = max(maxi, a[i + 1]);
            }

            i += 2;
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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.minMax(a, n);
        cout << maxi << endl
             << mini << endl;
    }
    return 0;
}
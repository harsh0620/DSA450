#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    bool find3Numbers(int a[], int n, int X)
    {
        sort(a, a + n);
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;

            while (l < r)
            {
                if (a[i] + a[l] + a[r] == X)
                {
                    return 1;
                }
                else if (a[i] + a[l] + a[r] < X)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
        }
        return 0;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, X;
        cin >> n >> X;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        cout << ob.find3Numbers(a, n, X);
        cout << endl;
    }
    return 0;
}

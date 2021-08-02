#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int sb(int a[], int n, int x)
    {
        int ans = INT_MAX;
        if (a[n - 1] > x)
        {
            return 1;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int cnt = 1;
            int sum = a[i];
            if (a[i] > x)
            {
                return 1;
            }
            for (int j = i + 1; j < n; j++)
            {
                if (sum + a[j] > x)
                {
                    cnt++;
                    ans = min(ans, cnt);
                    break;
                }
                else
                {
                    sum += a[j];
                    cnt++;
                }
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
        int n, m;
        cin >> n >> m;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        cout << ob.sb(a, n, m);
        cout << endl;
    }
    return 0;
}

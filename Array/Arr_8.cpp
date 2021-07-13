#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int kadanesAlgo(int a[], int n)
    {
        int maxSofar = INT_MIN;
        int maxEndingHere = 0;

        int i = 0;
        while (i < n)
        {
            maxEndingHere = maxEndingHere + a[i];
            if (maxSofar < maxEndingHere)
            {
                maxSofar = maxEndingHere;
            }
            if (maxEndingHere < 0)
            {
                maxEndingHere = 0;
            }
            i++;
        }

        return maxSofar;
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
        cout << ob.kadanesAlgo(a, n) << " ";
    }
    return 0;
}
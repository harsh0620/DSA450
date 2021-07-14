#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        // code here
        int i = 0, j = 0, k = n - 1;
        while (i <= k && j < m)
        {
            if (arr1[i] < arr2[j])
                i++;
            else
            {
                swap(arr2[j++], arr1[k--]);
            }
        }

        // Sort first array
        sort(arr1, arr1 + n);

        // Sort second array
        sort(arr2, arr2 + m);
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
        int a[n], b[m];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        ob.merge(a, b, n, m);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        for (int i = 0; i < m; i++)
        {
            cout << b[i] << " ";
        }
    }
    return 0;
}
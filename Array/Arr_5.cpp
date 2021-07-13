#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    void moveNegLeft1(int a[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                if (i != j)
                {
                    swap(a[i], a[j]);
                }
                j++;
            }
        }
    }
    void moveNegLeft2(int a[], int n)
    {
        int left = 0;
        int right = n - 1;

        while (left <= right)
        {
            if (a[left] > 0 && a[right] < 0)
            {
                swap(a[left], a[right]);
                left++;
            }
            else if (a[left] < 0 && a[right] > 0)
            {
                left++;
                right--;
            }
            else if (a[left] < 0 && a[right] < 0)
            {
                left++;
            }
            else
            {
                right--;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.moveNegLeft2(a, n);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
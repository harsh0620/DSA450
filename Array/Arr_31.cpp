#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    void threeWayPartition(int arr[], int n,
                           int lowVal, int highVal)
    {

        int start = 0, end = n - 1;
        for (int i = 0; i <= end;)
        {

            if (arr[i] < lowVal)
                swap(arr[i++], arr[start++]);
            else if (arr[i] > highVal)
                swap(arr[i], arr[end--]);
            else
                i++;
        }

        //We can also just sort the array but it take more time and arrangements.
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p, q;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> p >> q;
        Solution ob;
        ob.threeWayPartition(a, n, p, q);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

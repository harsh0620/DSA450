#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    void rightRotate(int a[], int n, int outOfPlace, int cur)
    {
        char temp = a[cur];
        for (int i = cur; i > outOfPlace; i--)
        {
            a[i] = a[i - 1];
        }
        a[outOfPlace] = temp;
    }
    void rearrange(int a[], int n)
    {
        int outOfPlace = -1;
        for (int index = 0; index < n; index++)
        {
            if (outOfPlace >= 0)
            {
                if (((a[index] >= 0) && (a[outOfPlace] < 0)) || ((a[index] < 0) && (a[outOfPlace] >= 0)))
                {
                    rightRotate(a, n, outOfPlace, index);
                    if (index - outOfPlace >= 2)
                        outOfPlace = outOfPlace + 2;
                    else
                        outOfPlace = -1;
                }
            }

            if (outOfPlace == -1)
            {
                if ((a[index] >= 0 && (!(index & 0x01))) || (a[index] < 0 && (index & 0x01)))
                {
                    outOfPlace = index;
                }
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
        int v[n];

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        ob.rearrange(v, n);
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    int findLongestConseqSubseq(int a[], int n)
    {
        //Your code here
        int freq[100000] = {0};
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            freq[a[i]]++;
            maxi = max(maxi, a[i]);
        }
        int ans = INT_MIN;
        int cnt = 0;
        for (int i = 0; i <= maxi; i++)
        {

            if (freq[i] == 0)
            {
                ans = max(ans, cnt);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return ans;
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
        cout << ob.findLongestConseqSubseq(a, n);
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;

int maxi = INT_MIN;
int mini = INT_MAX;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        //code here.
        int i = 0, j = 0, k = 0;
        vector<int> ans;
        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                ans.push_back(A[i]);
                i++;
                j++;
                k++;
            }
            else if (A[i] < B[j])
            {
                i++;
            }
            else if (B[j] < C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }
        vector<int>::iterator ip;
        ip = unique(ans.begin(), ans.begin() + ans.size());
        ans.resize(distance(ans.begin(), ip));
        return ans;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, o;
        cin >> n >> m >> o;
        int a[n], b[m], c[o];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < o; i++)
        {
            cin >> c[i];
        }
        Solution ob;
        vector<int> ans = ob.commonElements(a, b, c, n, m, o);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
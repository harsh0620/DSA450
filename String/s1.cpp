#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0; i < s.size() / 2; i++)
        {
            swap(s[i], s[n - 1 - i]);
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
        vector<char> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        Solution ob;
        ob.reverseString(s);
        for (int i = 0; i < n; i++)
        {
            cout << s[i];
        }

        cout << endl;
    }
    return 0;
}

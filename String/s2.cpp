#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    int isPalindrome(string S)
    {
        // Your code goes here
        int n = S.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (S[i] != S[n - i - 1])
            {
                return 0;
            }
        }
        return 1;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isPalindrome(s);

        cout << endl;
    }
    return 0;
}

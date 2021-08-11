#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    void printDups(string S)
    {
        map<char, int> mp;
        for (int i = 0; i < S.size(); i++)
        {
            mp[S[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second > 1)
            {
                cout << it.first << " count is:" << it.second << endl;
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
        string s;
        cin >> s;
        Solution ob;
        ob.printDups(s);

        cout << endl;
    }
    return 0;
}

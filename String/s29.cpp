#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    string findFirstRepeated(string s)
    {
        istringstream iss(s);
        string ans;
        unordered_map<string, int> mp;
        while (getline(iss, ans, ' '))
        {
            if (mp.find(ans) != mp.end())
            {
                mp[ans]++;
            }
            else
            {
                mp.insert(make_pair(ans, 1));
            }
        }
        istringstream iss1(s);
        while (getline(iss1, ans, ' '))
        {

            if (mp[ans] > 1)
            {
                return ans;
            }
        }
        return "NO";
    }
};
int main()
{
    Solution ob;

    string s;
    cin >> s;

    string firstWord = ob.findFirstRepeated(s);
    if (firstWord != "No")
        cout << "First repeated word :: "
             << firstWord << endl;
    else
        cout << "No";

    return 0;
}
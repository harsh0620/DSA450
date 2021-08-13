#include <bits/stdc++.h>
#define ll int long long int
using namespace std;
const int MAX = 100;

class Solution
{
public:
    void printSubsequence(string input, string output = "")
    {
        if (input.empty())
        {
            cout << output << endl;
            return;
        }
        printSubsequence(input.substr(1), output + input[0]);
        printSubsequence(input.substr(1), output);
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
        ob.printSubsequence(s);

        cout << endl;
    }
    return 0;
}
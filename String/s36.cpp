// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &sl)
    {
        // code here
        map<string, vector<int>> m;
        vector<vector<string>> ans;
        vector<string> temp;
        for (auto i : sl)
        {
            temp.push_back(i); // createing the copy of given vector
        }
        for (int i = 0; i < temp.size(); i++)
        {
            sort(temp[i].begin(), temp[i].end()); // sorting and storing the stings and indexes
            m[temp[i]].push_back(i);
        }
        for (auto i : m)
        {

            vector<string> v;
            for (int j = 0; j < i.second.size(); j++)
            {
                v.push_back(sl[i.second[j]]); // taking index from map and storing string from that index
            }
            ans.push_back(v);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        Solution ob;
        vector<vector<string>> result = ob.Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends
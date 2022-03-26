#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string start, string end, vector<string> &wordList)
    {
        queue<string> q;
        q.push(start);
        int wordSize = start.length();
        unordered_set<string> word;
        int n = wordList.size();
        for (int i = 0; i < n; i++)
        {
            word.insert(wordList[i]);
        }
        if (word.find(end) == word.end())
        {
            return 0;
        }
        int ans = 0;
        while (!q.empty())
        {
            ans++;
            int qSize = q.size();
            for (int i = 0; i < qSize; i++)
            {
                string s = q.front();
                q.pop();
                for (int j = 0; j < wordSize; j++)
                {
                    char temp = s[j];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        s[j] = ch;
                        if (s == end)
                        {
                            return ans + 1;
                        }
                        if (word.find(s) == word.end())
                        {
                            continue;
                        }
                        word.erase(s);
                        q.push(s);
                    }
                    s[j] = temp;
                }
            }
        }
        return 0;
    }
};
int main()
{
    return 0;
}
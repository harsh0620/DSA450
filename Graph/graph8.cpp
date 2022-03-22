#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int i, int j, vector<vector<int>> &vis, int n, int m, int newColor, int oldColor)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
        {
            return;
        }
        if (vis[i][j] || image[i][j] != oldColor)
        {
            return;
        }
        vis[i][j] = 1;
        image[i][j] = newColor;
        dfs(image, i + 1, j, vis, n, m, newColor, oldColor);
        dfs(image, i - 1, j, vis, n, m, newColor, oldColor);
        dfs(image, i, j + 1, vis, n, m, newColor, oldColor);
        dfs(image, i, j - 1, vis, n, m, newColor, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int oldColor = image[sr][sc];

        dfs(image, sr, sc, vis, n, m, newColor, oldColor);
        return image;
    }
};
int main()
{
    return 0;
}
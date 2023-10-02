#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int row, int col, int delrow[], int delcol[], int initialColor, int newcolor)
{
    ans[row][col] = newcolor;
    int n = image.size();
    int m = image[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 and ncol >= 0 and ncol < m and nrow < n and image[nrow][ncol] == initialColor and ans[nrow][ncol] != newcolor)
        {
            dfs(image, ans, nrow, ncol, delrow, delcol, initialColor, newcolor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans = image;
    int initialColor = image[sr][sc];
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    dfs(image, ans, sr, sc, delrow, delcol, initialColor, color);
    return ans;
}
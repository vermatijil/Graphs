#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numEnclaves(vector<vector<int>> &ans)
{
    int n = ans.size();
    int m = ans[0].size();
    // creating a visited vetor
    vector<vector<int>> visited(n, vector<int>(m, false));
    // creating a queue which contains a pair comprised of row and col of the ans
    queue<pair<int, int>> pendingNodes;
    // checking the boundaries of the ans for one
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // travering on the last row and col and first row and col
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (ans[i][j] == 1)
                {
                    pendingNodes.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
    }
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    while (pendingNodes.size() != 0)
    {
        int r = pendingNodes.front().first;
        int c = pendingNodes.front().second;
        pendingNodes.pop();
        // traversing in all the four directions of every pair of node in the pendingnode
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            // checking for the validity and required condition
            if (nrow >= 0 and ncol >= 0 and ncol < m and nrow < n and !visited[nrow][ncol] and ans[nrow][ncol] == 1)
            {
                pendingNodes.push({nrow, ncol});
                visited[nrow][ncol] = true;
            }
        }
    }
    // counting  the number of ones which are unvisited in the ans matrix
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == 1 and !visited[i][j])
            {
                count = count + 1;
            }
        }
    }
    return count;
}
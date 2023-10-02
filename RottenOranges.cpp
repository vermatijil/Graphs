#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>> &ans)
{
    int n = ans.size();
    int m = ans[0].size();
    queue<pair<pair<int, int>, int>> pendingNodes;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == 2)
            {
                pendingNodes.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }
    int time = 0;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    while (pendingNodes.size() != 0)
    {
        int r = pendingNodes.front().first.first;
        int c = pendingNodes.front().first.second;
        int t = pendingNodes.front().second;
        time = max(time, t);
        pendingNodes.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            // checking the validity and the condition
            if (nrow >= 0 and ncol >= 0 and ncol < m and nrow < n and !visited[nrow][ncol] and ans[nrow][ncol])
            {
                pendingNodes.push({{nrow, ncol}, t + 1});
                visited[nrow][ncol] = true;
            }
        }
    }
    // if all the fresh oranges are not convertes to rotten ornages then we reuturn -1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] != true and ans[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return time;
}
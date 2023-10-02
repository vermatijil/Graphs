#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool helper(vector<int> adj[], int n, vector<bool> &visited, int start, int parent)
{
    visited[start] = true;
    for (auto e : adj[start])
    {
        if (!visited[e])
        {
            if (helper(adj, n, visited, e, start))
            {
                return true;
            }
            if (parent != e)
                return true;
        }
    }
    return false;
}

bool CycleDFS(vector<int> adj[], int n, int start)
{
    vector<bool> visited(0, false);
    int parent = -1;
    return helper(adj, n, visited, start, parent);
}

bool CycleBFS(vector<int> adj[], int n, int start)
{
    vector<bool> visited(n, false);
    visited[start] = true;
    queue<pair<int, int>> pendingNodes;
    pendingNodes.push({start, -1});
    while (pendingNodes.size() != 0)
    {
        int node = pendingNodes.front().first;
        int parent = pendingNodes.front().second;
        pendingNodes.pop();
        for (auto e : adj[node])
        {
            if (!visited[e])
            {
                visited[e] = true;
                pendingNodes.push({e, node});
            }
            else if (e != parent)
                return true;
        }
    }
    return false;
}

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int start, vector<int> adj[], vector<bool> &visited, stack<int> &pendingNodes)
{
    visited[start] = true;
    for (auto e : adj[start])
    {
        if (!visited[e])
        {
            visited[e] = true;
            dfs(e, adj, visited, pendingNodes);
        }
    }
    pendingNodes.push(start);
}

vector<int> TopologicalSorting(vector<int> adj[], int n)
{
    vector<bool> visited(n, false);
    stack<int> pendingNodes;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, pendingNodes);
        }
    }
    vector<int> finalans;
    while (pendingNodes.size() != 0)
    {
        finalans.push_back(pendingNodes.top());
        pendingNodes.pop();
    }
    return finalans;
}
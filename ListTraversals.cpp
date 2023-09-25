#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printDFSList(vector<int> adj[], int n, int start, vector<bool> visited)
{
    cout << start << " ";
    visited[start] = true;
    for (auto it : adj[start])
    {
        if (!visited[it])
            printDFSList(adj, n, it, visited);
    }
}
void printBFSList(vector<int> adj[], int n, int start)
{
    vector<int> finalAns;
    vector<bool> visited(n, false);
    queue<int> pendingNodes;
    pendingNodes.push(start);
    visited[start] = true;
    while (pendingNodes.size() != 0)
    {
        int front = pendingNodes.front();
        pendingNodes.pop();
        finalAns.push_back(front);
        for (auto e : adj[front])
        {
            if (!visited[e])
            {
                visited[e] = true;
                pendingNodes.push(e);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        vector<int> adj[n];
        for (int i = 0; i < e; i++)
        {
            int s, f;
            cin >> s >> f;
            adj[s].push_back(f);
            adj[f].push_back(s);
        }
        int start;
        cin >> start;
        vector<bool> visited(n, false);
        cout << "DFS";
        printDFSList(adj, n, start, visited);
        cout << endl;
        cout << "BFS";
        printBFSList(adj, n, start);
        cout << endl;
    }
    return 0;
}
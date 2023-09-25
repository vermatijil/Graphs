#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printDFS(vector<vector<int>> &edges, int n, int start, vector<bool> &visited)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[i][start] == 1 and !visited[i] and i != start)
        {
            printDFS(edges, n, i, visited);
        }
    }
}
void printBFS(vector<vector<int>> &egdes, int start, int n)
{
    vector<bool> visited(n, false);
    queue<int> pendingNodes;
    visited[start] = true;
    pendingNodes.push(start);
    while (pendingNodes.size() != 0)
    {
        int front = pendingNodes.front();
        cout << front << " ";
        pendingNodes.pop();
        for (int i = 0; i < n; i++)
        {
            if (egdes[front][i] == 1 and !visited[i] and i != front)
            {
                visited[i] = true;
                pendingNodes.push(i);
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
        cin >> n >> e;
        vector<vector<int>> edges(n, vector<int>(n, 0));
        for (int i = 0; i < e; i++)
        {
            int f, s;
            cin >> f >> s;
            edges[s][f] = 1;
            edges[f][s] = 1;
        }
        int start;
        cin >> start;
        vector<bool> visited(n, false);
        cout << "Bfs" << endl;
        printBFS(edges, start, n);
        cout << endl;
        cout << "Dfs" << endl;
        printDFS(edges, n, start, visited);
        cout << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<int> adj[], int n)
{
    vector<int> color(n, -1);
    color[0] = 0;
    queue<int> pendingnodes;
    pendingnodes.push(0);
    while (pendingnodes.size() != 0)
    {
        int front = pendingnodes.size();
        pendingnodes.pop();
        for (auto e : adj[front])
        {
            if (color[e] == -1)
            {
                color[e] = !color[front];
            }
            else if (color[front] == color[e])
            {
                return false;
            }
        }
    }
    return true;
}

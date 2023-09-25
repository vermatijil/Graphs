#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &ans, int n, int start, vector<bool> &visted)
{
    visted[start] = true;
    for (int i = 0; i < n; i++)
    {
        if (ans[i][start] == 1 and !visted[i])
        {
            dfs(ans, n, i, visted);
        }
    }
}

int FindProvinces(vector<vector<int>> &ans)
{
    int count = 0;
    int n = ans.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(ans, n, i, visited);
            count = count + 1;
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> edges(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            int s, f;
            cin >> s >> f;
            edges[s][f] = 1;
            edges[f][s] = 1;
        }

        cout << FindProvinces(edges);
        cout << endl;
    }
    return 0;
}
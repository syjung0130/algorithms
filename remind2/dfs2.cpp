#include <vector>
#include <iostream>

using namespace std;

int dfs_r(vector<vector<int>> &graph, int node, vector<bool> &visited)
{
    if (visited[node] == false) {
        visited[node] = true;
        cout << node << " ";
        for (auto vertex : graph[node]) {
            dfs_r(graph, vertex, visited);
        }
    }
    return 1;
}

void dfs_s(vector<vector<int>> &graph, int node)
{
    vector<bool> visited(graph.size(), false);
    vector<int> s = {node};

    while (s.size() > 0) {
        int v = s.back();//s[s.size()-1];
        if (visited[v] == false) {
            s.pop_back();
            visited[v] = true;
            cout << v << " ";
            for (auto i : graph[v]) {
                s.push_back(i);
            }
        }
    }
}

int main()
{

    vector<vector<int>> graph = {
        {},
        {2, 3, 4},
        {5},
        {},
        {},
        {6, 7},
        {},
        {},
    };

    cout << "graph size: " << graph.size() << endl;
    vector<bool> visited(graph.size(), false);

    dfs_r(graph, 1, visited);
    cout << endl;

    dfs_s(graph, 1);

    return 0;
}
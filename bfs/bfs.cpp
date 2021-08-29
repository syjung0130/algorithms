#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#if 0
       1
     / | \
    3  |   2
  / |  |    \
 4  5  |     7
       |  /  |
        8    6
map<int, list<int>> graph = {
    {0, {}},
    {1, {2, 3, 8}},
    {2, {1, 7}},
    {3, {1, 4, 5}},
    {4, {3, 5}},
    {5, {3, 4}},
    {6, {7}},
    {7, {2, 6, 8}},
    {8, {1, 7}}
};
#endif

int getVisitedNodeNum(vector<vector<int>> &graph, vector<bool> &visited, int v) {
    int visitedNodeNum = 0;

    for (int i = 0; i < graph[v].size(); i++) {
        if (visited[graph[v][i]] == true) {
            visitedNodeNum++;
        }
    }

    return visitedNodeNum;
}

void bfs(vector<vector<int>> &graph, int startNode, vector<bool> &visited) {
    cout << "bfs()" << endl;

    queue<int> q;
    int v = startNode;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();
        if (visited[v] == false) {
            cout << v << ", ";
            visited[v] = true;
        }
        for (int i = 0; i < graph[v].size(); i++) {
            if (visited[graph[v][i]] == false) {
                q.push(graph[v][i]);
            }
        }
    }
}

int main() {

    vector<vector<int>> graph = {
        {},
        {2, 3, 8},
        {1, 7},
        {1, 4, 5},
        {3, 5},
        {3, 4},
        {7},
        {2, 6, 8},
        {1, 7},
    };

    int node_num = graph.size();
    cout << "node_num: " << node_num << endl;

    vector<bool> visited;
    for (int i = 0; i < node_num; i++) {
        visited.push_back(false);
    }

    bfs(graph, 1, visited);

    return 0;
}
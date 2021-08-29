#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int dfs_recursive(vector<vector<int>> &graph, int v, vector<bool> &visited) {

    visited[v] = true;
    cout << v << ", ";
    for (auto i : graph[v]) {
        if (visited[i] == false) {
            dfs_recursive(graph, i, visited);
        }
    }

    return 1;
}

void dfs_stack(vector<vector<int>> &graph, int node) {
    vector<bool> visited;
    stack<int> s;

    for (int i = 0; i < graph.size(); i++)
        visited.push_back(false);

    s.push(node);
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (visited[v] == false) {
            visited[v] = true;
            cout << v << ", ";
        }
        for (auto i : graph[v]) {
            if (visited[i] == false) {
                s.push(i);
            }
        }
    }
}

int main() {
#if 0
       1
     / | \
    2  3   4
    |  
    5  
   / \ 
  6   7
#endif
    vector<vector<int>> graph = {
        {},
        {2, 3, 4},  //1
        {5},        //2
        {},         //3
        {},         //4
        {6, 7},     //5
        {},         //6
        {},         //7
    };
    vector<bool> visited;

    for (int i = 0; i < 9; i++)
        visited.push_back(false);

    dfs_recursive(graph, 1, visited);
    cout << endl;

    // dfs(graph, 1);
    dfs_stack(graph, 1);

    return 0;
}

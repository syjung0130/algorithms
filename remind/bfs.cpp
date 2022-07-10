#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void bfs(vector<vector<int>> &graph, int startNode, vector<bool> &visited) {
    cout << "bfs()" << endl;

    queue<int> q;
    int v = startNode;
    
    q.push(v);
    while (!q.empty()) {
        v = q.front();
        q.pop();

        if (visited[v] == false) {
            visited[v] = true;
            cout << v << ", ";
            for (int i = 0; i < graph[v].size(); i++) {
                q.push(graph[v][i]);
            }
        }
        // for (int i = 0; i < graph[v].size(); i++) {
        //     if (visited[graph[v][i]] == false) {
        //         q.push(graph[v][i]);
        //     }
        // }
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
        {5},        //3
        {},         //4
        {6, 7},     //5
        {},         //6
        {3},        //7
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

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <stack>

using namespace std;

void printVisited(vector<bool> &v) {
    cout << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void printAdjacent(list<int> &adj, vector<bool> &v) {
    cout << "===== printAdjacent() =====" << endl;
    cout << boolalpha;
    for (auto it = adj.begin(); it != adj.end(); it++) {
        cout << "[" << *it << "]: " << v[*it] << endl;
    }
    cout << "===========================" << endl;
}

int countUnvisited(list<int> &adj, vector<bool> &v) {
    int cnt_unvisited = 0;
    for (auto it = adj.begin(); it != adj.end(); it++) {
        // cout << "[" << *it << "]: " << v[*it] << endl;
        if (v[*it] == false)
            cnt_unvisited++;
    }
    return cnt_unvisited;
}

int dfs_recursive(vector<vector<int>> &graph, int v, vector<bool> &visited) {

    visited[v] = true;
    cout << v << " ";

    for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
        if (!visited[*it])
            dfs_recursive(graph, *it, visited);
    }

    return 1;
}

void dfs_stack(vector<vector<int>> &graph, int node) {
    vector<bool> visited;
    stack<int> s;

    for (int i = 0; i < graph.size(); i++) {
        visited.push_back(false);
    }

    s.push(node);
    while (!s.empty()) {
        int v = s.top();
        s.pop();
        if (visited[v] == false) {
            cout << v << ", ";
            visited[v] = true;
        }
        for (auto i : graph[v]) {
            if (visited[i] == false) {
                s.push(i);
            }
        }
    }
}

int dfs(map<int, list<int>> graph, int node) {
    vector<bool> visited;
    stack<int> s;
    int depth = graph.size();

    for (int i = 0; i < 9; i++) {
        visited.push_back(false);
    }

    int v = node;
    visited[v] = true;
    s.push(v);
    cout << s.top() << " ";
    int adj = 0;

    while (!s.empty()) {
        for (auto it = graph[v].begin(); it != graph[v].end(); it++) {//인접노드 찾기.
            if (visited[*it] == false) {
                adj = *it;
                break;
            }
        }

        if (visited[adj] == false) {//인접노드 중 첫번째 노드를 방문하지 않았다면 방문 후, stack에 넣는다.
            cout << adj << " ";
            visited[adj] = true;
            v = adj;
            s.push(adj);
        }
        else {//인접노드를 방문했다면,
            v = s.top();
            if (countUnvisited(graph[v], visited) == 0) {//방문하지 않은 노드가 하나라도 있다면 pop하지 않늗다.
                s.pop();//모두 방문했을 경우에만 pop한다.
            }
        }
    }

    return 1;
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
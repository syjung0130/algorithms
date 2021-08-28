#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//        1
//      / | \
//     3  |   2
//   / |  |    \
//  4  5  |     7
//        |  /  |
//         8    6
// map<int, list<int>> graph = {
//     {0, {}},
//     {1, {2, 3, 8}},
//     {2, {1, 7}},
//     {3, {1, 4, 5}},
//     {4, {3, 5}},
//     {5, {3, 4}},
//     {6, {7}},
//     {7, {2, 6, 8}},
//     {8, {1, 7}}
// };

int getVisitedNodeNum(map<int, vector<int>> &graph, vector<bool> &visited, int v) {
    int visted_node_num = 0;

    for (int i = 0; i < graph[v].size(); i++) {
        if (visited[graph[v][i]] == true) {// if (visited[graph[v][i]] == false) {
            // q.push(graph[v][i]);
            visted_node_num++;
        }
    }

    return visted_node_num;
}

void bfs(map<int, vector<int>> &graph, int node, vector<bool> &visited) {
    cout << "bfs()" << endl;
#if 0
## 너비 우선 탐색의 수행 순서
 - 1. 탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다.  
 - 2. 큐에서 노드를 꺼내서 해당 노드의 인접 노드 중에서  
 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리를 한다.  
 - 3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다.
#endif
    queue<int> q;
    int v = node;
    q.push(v);
    visited[v] = true;
    int visted_node_num = 0;

    while(!q.empty()) {//q가 비어있지 않으면.
        
        //인접노드를 찾는다.
        v = q.front();
        q.pop();
        // if (count(visited.begin(), visited.end(), true) == 8) break;
        //방문 처리
        cout << v << " ";//방문
        visited[v] = true;
        visted_node_num = getVisitedNodeNum(graph, visited, v);
        if (visted_node_num == graph[v].size()) {//인접 노드들이 모두 방문된 상태라면,
            q.pop();
            continue;//skip enqueue adj
        }
        else {//인접 노드들 중에 방문한 노드가 하나라도 있다면, 큐에 인접 노드를 넣는다.
            for (int i = 0; i < graph[v].size(); i++) {
                if (visited[graph[v][i]] == false) {
                    q.push(graph[v][i]);//enqueue adj
                }
            }
        }
    }

    cout << endl;
}

int main() {
    map<int, vector<int>> graph = {
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

    int node_num = graph.size();
    cout << "node_num: " << node_num << endl;

    vector<bool> visited;
    for (int i = 0; i < node_num; i++) {
        visited.push_back(false);
    }

    //1 2 3 8 7 4 5 6
    bfs(graph, 1, visited);

    return 0;
}
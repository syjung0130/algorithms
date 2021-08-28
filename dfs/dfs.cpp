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

#if 0
int dfs(map<int, list<int>> &graph, int v, bool visited[]) {

    visited[v] = true;
    cout << v << " ";

    for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
        if (!visited[*it])
            dfs(graph, *it, visited);
    }

    return 1;
}
#else
int dfs_recursive(map<int, list<int>> &graph, int v, bool visited[]) {

    visited[v] = true;
    cout << v << " ";

    for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
        if (!visited[*it])
            dfs_recursive(graph, *it, visited);
    }

    return 1;
}
/*
	for (i <- 0; i < n; i <-i+1) do {
		visited[i] <- false;
	}
	stack <- createStack();
	visited[v] <- true;
	v 방문;
	
	while(not isEmpty(stack)) do {
		if (visited[v의 인접 정점 w]=false) then {
            push(stack, v);
            visited[w] <- true;
            w 방문;
            v <- w;
        }
        else 
            v <- pop(stack);
	}
*/
/*
procedure DFS_iterative(G, v) is
    let S be a stack
    S.push(iterator of G.adjacentEdges(v))
    while S is not empty do
        if S.peek().hasNext() then
            w = S.peek().next()
            if w is not labeled as discovered then
                label w as discovered
                S.push(iterator of G.adjacentEdges(w))
        else
            S.pop() 
*/
// int dfs(map<int, list<int>> graph, int node) {
//     vector<bool> visited;
//     stack<int> s;
//     int depth = graph.size();

//     for (int i = 0; i < 9; i++) {
//         visited.push_back(false);
//     }

//     int v = node;
//     visited[v] = true;
//     s.push(v);
//     cout << s.top() << " ";
//     int adj = 0;

//     while (!s.empty()) {
//         //인접노드 찾기.
//         for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
//             if (visited[*it] == false) {
//                 adj = *it;
//                 break;
//             }
//         }

//         // cout << endl << "v: " << v << ", adj: " << adj << endl;
//         cout << "size: " << graph[v].size() << ", " << graph[adj].size() << endl;

//         if (visited[adj] == false) {
//             cout << adj << " ";
//             visited[adj] = true;
//             v = adj;
//             s.push(adj);
//         }
//         else {

// //        1
// //      / | \
// //     3  |   2
// //   / |  |    \
// //  4  5  |     7
// //        |  /  |
// //         8    6
//     // map<int, list<int>> graph = {
//     //     {0, {}},
//     //     {1, {2, 3, 8}},
//     //     {2, {1, 7}},
//     //     {3, {1, 4, 5}},
//     //     {4, {3, 5}},
//     //     {5, {3, 4}},
//     //     {6, {7}},
//     //     {7, {2, 6, 8}},
//     //     {8, {1, 7}}
//     // };

// #if 0
// root@3b6edeb4ca1e:/workdir/code/coding_test/data_structure# ./dfs
// 1 2 7 6 8 3 4 5 
// 1 2 7 6 s pop: 6, s size: 4
// s pop: 7, s size: 3
// 8 s pop: 8, s size: 3
// s pop: 2, s size: 2
// s pop: 1, s size: 1
// #endif
//             // cout << "s pop: " << s.top() << ", s size: " << s.size() << endl;
//             v = s.top();
//             if (v == 1) {
//                 printAdjacent(graph[v], visited);
//                 cout << "count: " << countUnvisited(graph[v], visited) << endl;
//             }

//             if (countUnvisited(graph[v], visited) == 0) {
//                 s.pop();
//             }

//             // s.pop();
//         }
//         // cout << s << endl;
//     }

//     return 1;
// }
#endif

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

void addEdge(map<int, list<int>> &graph, int v, int w) {
    graph[v].push_back(w);
}

int main() {

#if 1
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
#else
    map<int, list<int>> graph;
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 8);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 7);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 3);
    addEdge(graph, 5, 4);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 2);
    addEdge(graph, 7, 6);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 1);
    addEdge(graph, 8, 7);

#endif

    bool visited[9] = {false};

    for (int i = 0; i < 9; i++) {
        visited[i] = false;
    }

    dfs_recursive(graph, 1, visited);
    cout << endl;

    dfs(graph, 1);

    return 0;
}
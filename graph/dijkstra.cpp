#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();

struct less_comp {
    constexpr bool operator() (
        pair<int, int> const& a,
        pair<int, int> const& b) const noexcept
    {
        return a.second > b.second;
    }
};

#if 0
vector< vector<pair<int, int>> > graph = {
    {{INF, INF},},
    {{2, 2}, {3, 5}, {4, 1}}, //node 1과 연결된 (node 번호, node 1과의 거리)
    {{3, 3}, {4, 2}}, //node 2와 연결된 (node 번호, node 2와의 거리)
    {{2, 3}, {6, 5}}, //node 3과 연결된 (node 번호, node 3과의 거리)
    {{3, 3}, {5, 1}}, //node 4와 연결된 (node 번호, node 4와의 거리)
    {{3, 1}, {6, 2}}, //node 5와 연결된 (node 번호, node 5와의 거리)
    {{INF, INF},},//node 6에서 다른 노드로 가는 간선이 없으므로 INF 처리.
};
#else
vector< vector<pair<int, int>> > graph;

void generateGraph(int depth) {
    //0번째 노드는 없는 것으로 간주하여 INF 처리하기 때문에,
    //크기를 하나 더 할당한다.
    graph.reserve(depth+1);
    graph.resize(depth+1);
}

void addNode(int node, pair<int, int> neighborNode) {

    if (graph.empty()) {
        graph[0].push_back(make_pair(INF, INF));
    }

    graph[node].push_back(neighborNode);
}
#endif

void printDistance(vector<int> &distance) {
    cout << "printDistance(): " << distance.size() << endl;

    auto it = distance.begin();
    for (;it != distance.end(); it++) {
        cout << *it << endl;
    }
}

void genDijkstraDistance(int start_node, vector<int> &distance) {
    cout << "genDijkstraDistance()" << endl;
    priority_queue<int, vector<pair<int, int>>, less_comp> q;

    q.push(make_pair(start_node, 0));
    distance[start_node] = 0;

    cout << std::boolalpha << "q.size: " << q.size() 
            << "q.empty: " << q.empty() << endl;

    while (q.empty() == false) {
        pair<int, int> item = q.top();
        q.pop();

        int now = item.first;
        int dist = item.second;
        // cout << "now: " << now << ", dist: " << dist << endl;
        // cout << "distance: " << distance[now] << endl;

        if (distance[now] < dist) {
            continue;
        }
        
        for (auto it = graph[now].begin();it != graph[now].end(); it++) {
            if (it->first == INF) {
                continue;
            }
            int cost = dist + it->second;

            if (cost < distance[it->first]) {
                distance[it->first] = cost;
                q.push(make_pair(it->first, cost));
            }
        }

    }
    
}

int main() {
    cout << "main()" << endl;
#if 0
    cout << "graph size: " << graph.size() << endl;
    // vector<int> distance;
    // distance.reserve(graph.size());
    vector<int> distance(graph.size());
    fill(distance.begin(), distance.end(), INF);
    cout << "distance vector size: " << distance.size() << endl;
#else
    generateGraph(6);
    addNode(1, make_pair(2, 2));
    addNode(1, make_pair(3, 5));
    addNode(1, make_pair(4, 1));

    addNode(2, make_pair(3, 3));
    addNode(2, make_pair(4, 2));

    addNode(3, make_pair(2, 3));
    addNode(3, make_pair(6, 5));

    addNode(4, make_pair(3, 3));
    addNode(4, make_pair(5, 1));

    addNode(5, make_pair(3, 1));
    addNode(5, make_pair(6, 2));

    vector<int> distance(graph.size());
    fill(distance.begin(), distance.end(), INF);
    cout << "distance vector size: " << distance.size() << endl;
#endif
    genDijkstraDistance(1, distance);

    printDistance(distance);

    return 0;
}


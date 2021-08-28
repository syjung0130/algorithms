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

class DijkstraGraph {
public:
void generateGraph(int depth) {
    //0번째 노드는 없는 것으로 간주하여 INF 처리하기 때문에,
    //크기를 하나 더 할당한다.
    graph.reserve(depth+1);
    graph.resize(depth+1);
}

DijkstraGraph(int size) {
    generateGraph(size);
}

int size() {
    return graph.size();
}

void addNode(int node, pair<int, int> neighborNode) {

    if (graph.empty()) {
        graph[0].push_back(make_pair(INF, INF));
    }

    graph[node].push_back(neighborNode);
}

void printDistance(vector<int> &distance) {
    cout << "printDistance(): " << distance.size() << endl;

    auto it = distance.begin();
    for (;it != distance.end(); it++) {
        cout << *it << endl;
    }
}

void generateDistance(int start_node, vector<int> &distance) {
    cout << "generateDistance()" << endl;
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

private:
DijkstraGraph() {
}

vector< vector<pair<int, int>> > graph;

};


int main() {
    cout << "main()" << endl;

    DijkstraGraph dijkstraGraph(6);

    dijkstraGraph.addNode(1, make_pair(2, 2));
    dijkstraGraph.addNode(1, make_pair(3, 5));
    dijkstraGraph.addNode(1, make_pair(4, 1));

    dijkstraGraph.addNode(2, make_pair(3, 3));
    dijkstraGraph.addNode(2, make_pair(4, 2));

    dijkstraGraph.addNode(3, make_pair(2, 3));
    dijkstraGraph.addNode(3, make_pair(6, 5));

    dijkstraGraph.addNode(4, make_pair(3, 3));
    dijkstraGraph.addNode(4, make_pair(5, 1));

    dijkstraGraph.addNode(5, make_pair(3, 1));
    dijkstraGraph.addNode(5, make_pair(6, 2));

    vector<int> distance(dijkstraGraph.size());
    fill(distance.begin(), distance.end(), INF);
    cout << "distance vector size: " << distance.size() << endl;

    dijkstraGraph.generateDistance(1, distance);

    dijkstraGraph.printDistance(distance);

    return 0;
}


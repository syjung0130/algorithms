#include <iostream>
#include <limits>
#include <vector>
#include <map>

using namespace std;

const int INF = numeric_limits<int>::max();

int main()
{
    cout << "main()" << endl;

    int n = 6, m = 11;
// [[], [(2, 2), (3, 5), (4, 1)], [(3, 3), (4, 2)], [(2, 3), (6, 5)], 
//      [(3, 3), (5, 1)], [(3, 1), (6, 2)], []]
    vector< vector<map<int, int>> > graphV = {
        {{INF, INF},},
        {{2, 2}, {3, 5}, {4, 1}},
        {{3, 3}, {4, 2}},
        {{2, 3}, {6, 5}},
        {{3, 3}, {5, 1}},
        {{3, 1}, {6, 2}},
        {{INF, INF},},
    };
}
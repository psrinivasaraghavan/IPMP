#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();


int minCostPath(vector<vector<int>> &graph, int start, int end) {
    int n = graph.size();
    vector<int> cost(n, INF);
    cost[start] = 0;
    for (int i = start; i <= end; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (graph[j][k] != INF) {
                    cost[k] = min(cost[k], cost[j] + graph[j][k]);
                }
            }
        }
    }
    return cost[end];
}


int main() {
    vector<vector<int>> graph = {
        {0, 10, 3, INF},
        {INF, 0, INF, 5},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };
    int start = 0, end = 3;
    int minCost = minCostPath(graph, start, end);
    cout << "Minimum cost path from node " << start << " to node " << end << " is: " << minCost << endl;
    return 0;
}

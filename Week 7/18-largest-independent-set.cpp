#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
int n, dp[MAXN][2], size[MAXN], parent[MAXN];
bool visited[MAXN];
vector<int> adjList[MAXN];


void dfs(int u) {
    visited[u] = true;
    size[u] = 1;
    dp[u][1] = 1;
    for (int v : adjList[u]) {
        if (visited[v]) continue;
        parent[v] = u;
        dfs(v);
        size[u] += size[v];
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}


int largestIndependentSet() {
    int root = 1;
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(root);
    int ans = max(dp[root][0], dp[root][1]);
    while (root != 1) {
        int p = parent[root];
        int t0 = dp[p][0], t1 = dp[p][1];
        dp[p][0] -= max(dp[root][0], dp[root][1]);
        dp[p][1] -= dp[root][0];
        size[p] -= size[root];
        dp[root][0] = max(t0, t1 + dp[root][0]);
        dp[root][1] = t0 + dp[root][1];
        size[root] = n - size[root];
        ans = max(ans, max(dp[root][0], dp[root][1]));
        root = p;
    }
    return ans;
}


int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the edges of the graph: ";
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout << "Size of the largest independent set: " << largestIndependentSet() << endl;
    return 0;
}
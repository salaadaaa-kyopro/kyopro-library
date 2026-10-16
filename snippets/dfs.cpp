#include <bits/stdc++.h>

using namespace std;

void dfs(const long long u, const vector<vector<long long>>& G, vector<bool>& visited, vector<bool>& seen){
    visited[u] = true;
    for (long long v : G[u]) {
        if (!visited[v]) {
            dfs(v, G, visited, seen);
        }
    }
    seen[u] = true;
    visited[u] = false;
    return;
}

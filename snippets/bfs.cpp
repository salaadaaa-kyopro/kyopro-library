#include <bits/stdc++.h>

using namespace std;

void bfs(const vector<vector<long long>>& G, const long long start){
    vector<bool> visited(G.size(), false);
    queue<long long> Q;
    Q.push(start);
    visited[start] = true;
    while(!Q.empty()){
        long long u = Q.front();
        Q.pop();
        for (long long v : G[u]) {
            if (!visited[v]) {
                visited[v] = true;
                Q.push(v);
            }
        }
    }
}
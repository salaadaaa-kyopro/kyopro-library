#include <bits/stdc++.h>

using namespace std;
struct Edge{
    long long from;
    long long to;
    long long w;
    Edge(long long from, long long to, long long w) : from(from), to(to), w(w) {}
    bool operator>(Edge* other) const {
        return this->w > other->w;
    }
    bool operator<(Edge* other) const {
        return other > this;
    }
};
using Graph = vector<vector<Edge>>;

void dijkstra(const Graph& G, vector<long long>& D, const long long start){
    D[start] = 0;
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> Q;
    Q.push({D[start], start});
    while(!Q.empty()){
        long long v = Q.top().second;
        long long d = Q.top().first;
        Q.pop();
        if(d > D[v]) continue;
        for (const Edge& e : G[v]) {
            if(D[e.to] > D[v] + e.w){
                D[e.to] = D[v] + e.w;
                Q.push({D[e.to], e.to});
            }
        }
    }
}

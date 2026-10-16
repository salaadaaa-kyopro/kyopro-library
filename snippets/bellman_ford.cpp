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
const long long INF = 1ll<<61;

bool bellman_ford(const Graph& G, vector<long long>& D, const long long start){
    long long n = G.size();
    D[start] = 0;
    for(int i=0;i<n;i++){
        bool update = false;
        for(int v=0;v<n;v++){
            if(D[v] == INF) continue;
            for (const Edge& e : G[v]) {
                if(D[e.to] > D[v] + e.w){
                    update = true;
                    D[e.to] = D[v] + e.w;
                }
            }
        }
        if(!update) return false;
        if(i == n-1 && update) return true;
    }
    return false;
}

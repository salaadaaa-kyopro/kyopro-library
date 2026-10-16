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

bool Floyd_Warshall(const Graph& G, vector<vector<long long>>& D, const long long n){
    for(int v=0;v<n;v++){
        D[v][v] = 0;
        for (const Edge& e : G[v]) {
            D[v][e.to] = e.w;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
    for(int v=0;v<n;v++){
        if(D[v][v] < 0){
            return true;
        }
    }
    return false;
}

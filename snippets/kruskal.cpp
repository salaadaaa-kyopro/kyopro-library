#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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

vector<vector<Edge>> Kruskal(const vector<vector<Edge>>& G){
    priority_queue<pair<long long,pair<long long,long long>>, vector<pair<long long,pair<long long,long long>>>, greater<pair<long long,pair<long long,long long>>>> Q;
    const long long n = G.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<G[i].size();j++){
            Q.push({G[i][j].w,{i,j}});
        }
    }
    dsu uf(n);
    vector<vector<Edge>> F(n);
    while(!Q.empty()){
        long long w; pair<long long, long long> idx;
        tie(w,idx) = Q.top();
        Q.pop();
        long long i,j; tie(i,j) = idx;
        const Edge e = G[i][j];
        const long long u = e.from, v = e.to;
        if(!uf.same(u, v)){
            F[u].emplace_back(e);
            uf.merge(u, v);
        }
    }
    return F;
}

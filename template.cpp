//https://github.com/salaadaaa-kyopro/kyopro-library.git

#ifdef LOCAL
#include "pch.hpp"
#else
#include <bits/stdc++.h>
#endif

//#define ACL_included
#ifdef ACL_included
#include <atcoder/all>
using namespace atcoder;
#endif

# pragma GCC optimize("O3,unroll-loops")
# pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

using namespace std;
using ll = long long;
using ldbl = long double;
using ull = unsigned long long;
using gll = greater<ll>;
template <typename T>
using vec = vector<T>;
template <typename T>
using vvec = vector<vec<T>>;
template <typename T>
using vvvec = vector<vvec<T>>;
template <typename T>
using vvvvec = vector<vvvec<T>>;
template <typename T>
using uset = unordered_set<T>;
template <typename T, typename U>
using umap = unordered_map<T, U>;
template <typename T>
using pque = priority_queue<T>;
template <typename T>
using rpque = priority_queue<T,vec<T>,greater<T>>;
template <typename T>
using deq = deque<T>;
using vll = vec<ll>;
using vbool = vec<bool>;
using vstr = vec<string>;
using vchar = vec<char>;
using vldbl = vec<ldbl>;
using vvll = vvec<ll>;
using vvbool = vvec<bool>;
using vvstr = vvec<string>;
using vvchar = vvec<char>;
using vvldbl = vvec<ldbl>;
template <typename T, typename U>
using vpair = vec<pair<T, U>>;
template <typename T, typename U>
using vvpair = vvec<pair<T, U>>;
using pll = pair<ll,ll>;
using usll = uset<ll>;
using umll = umap<ll,ll>;
using dqll = deq<ll>;
using pqll = pque<ll>;
using rpqll = rpque<ll>;
using qll = queue<ll>;
using vpll = vpair<ll,ll>;
using vvpll = vec<vpll>;

#ifdef ACL_included
using namespace atcoder;
using mint = modint998244353;
using vmint = vec<mint>;
using vvmint = vvec<mint>;
#endif


#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i,n) for(ll i=1;i<=(ll)(n);i++)
#define repab(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define rrep(i,a,b) for(ll i=(ll)(a);i>=(ll)(b);i--)
#define repv(e,v) for(auto& e: v)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define Yes cout << "Yes" << endl
#define No cout << "No" << endl

#define YorN(x) if(x){Yes;}else{No;} 


const ll INF = 1ll<<61;

const vll DX = {1,0,-1,0,1,-1,-1,1};
const vll DY = {0,1,0,-1,1,1,-1,-1};



template<typename T> size_t HashCombine(const size_t seed,const T &v){
    return seed^(std::hash<T>()(v)+0x9e3779b9+(seed<<6)+(seed>>2));
}

template<typename T, typename S> struct std::hash<std::pair<T,S>>{
    size_t operator()(const std::pair<T,S> &keyval) const noexcept {
        return HashCombine(std::hash<T>()(keyval.first), keyval.second);
    }
};


template <typename T>
bool chmax(T& a, const T& b){
    if(a < b){ a = b; return true; }
    return false;
}

template <typename T>
bool chmin(T& a, const T& b){
    if(a > b){ a = b; return true; }
    return false;
}


template <typename T, typename U>
inline istream& operator>>(istream& is, pair<T,U>& p){
    is >> p.first >> p.second;
    return is;
}

template <typename T>
inline istream& operator>>(istream& is, vector<T>& v) {
    rep(i, v.size()) is >> v[i];
    return is;
}

template <typename T>
inline istream& operator>>(istream& is, vector<vector<T>>& v) {
    rep(i, v.size()) is >> v[i];
    return is;
}


template <typename T, typename U>
inline ostream& operator<<(ostream& os, pair<T,U>& p){
    os << p.first << ' ' << p.second;
    return os;
}

template <typename T>
inline ostream& operator<<(ostream& os, vector<T>& v) {
    rep(i, v.size()) os << v[i] << (i+1==v.size() ? "" : " ");
    return os;
}

template <typename T>
inline ostream& operator<<(ostream& os, vector<vector<T>>& v) {
    rep(i, v.size()){
        os << v[i];
        if(i+1 != v.size()) os << endl;
    }
    return os;
}


#ifdef ACL_included
inline istream& operator>>(istream& is, modint& n) {
    long long N; is >> N; n = N;
    return is;
}

inline ostream& operator<<(ostream& os, modint& n) {
    os << n.val();
    return os;
}

template<int m>
inline istream& operator>>(istream& is, static_modint<m>& n) {
    long long N; is >> N; n = N;
    return is;
}

template<int m>
inline ostream& operator<<(ostream& os, static_modint<m>& n) {
    os << n.val();
    return os;
}
#endif

template<class T>
T Min(T a) {
    return a;
}
template<class T, class... Args>
T Min(T x, Args... a) {
    return min(x , Min(a...));
}

template <typename T>
T Min(const vector<T>& v){
    T ans = INF;
    for(const T& e : v) chmin(ans, e);
    return ans;
}


template<class T>
T Max(T a) {
    return a;
}
template<class T, class... Args>
T Max(T x, Args... a) {
    return max(x , Max(a...));
}
template <typename T>
T Max(const vector<T>& v){
    T ans = -INF;
    for(const T& e : v) chmax(ans, e);
    return ans;
}

template<class T>
T Sum() {
    return 0;
}
template<class T, class... Args>
T Sum(T x, Args... a) {
    return (x + ... + a);
}

template <typename T>
T Sum(const vector<T>& v){
    T ans = 0;
    for(const T& e : v) ans += e;
    return ans;
}

template<class T>
T Prod() {
    return 1;
}
template<class T, class... Args>
T Prod(T x, Args... a) {
    return (x * ... * a);
}

template <typename T>
T Prod(const vector<T>& v){
    T ans = 1;
    for(const T& e : v) ans *= e;
    return ans;
}

template<class T>
T Xor() {
    return 0;
}
template<class T, class... Args>
T Xor(T x, Args... a) {
    return (x ^ ... ^ a);
}

template <typename T>
T Xor(const vector<T>& v){
    T ans = 0;
    for(const T& e : v) ans ^= e;
    return ans;
}


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

using Graph = vec<vec<Edge>>;


void G_in(vector<vector<long long>>& G, const int m){
    for(int i=0;i<m;i++){
        long long u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
}

void G_in1(vector<vector<long long>>& G, const int m){
    for(int i=0;i<m;i++){
        long long u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
    }
}

void w_G_in(Graph& G, const int m){
    for(int i=0;i<m;i++){
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(Edge{u, v, w});
        G[v].emplace_back(Edge{v, u, w});
    }
}

void w_G_in1(Graph& G, const int m){
    for(int i=0;i<m;i++){
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(Edge{u, v, w});
    }
}



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    
    
    
    return 0;
}

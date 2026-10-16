#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<vector<T>> operator*(vector<vector<T>>& V, vector<vector<T>>& W){
    vector<vector<T>> R(V.size(), vector<T>(W[0].size()));
    for(int i=0;i<V.size();i++){
        for(int k=0;k<W.size();k++){
            for(int j=0;j<W[0].size();j++){
                R[i][j] += V[i][k] * W[k][j];
            }
        }
    }
    return R;
}
template <typename T>
vector<vector<T>> powmat(const vector<vector<T>>& A, const long long b){
    const long long n = A.size();
    vector<vector<T>> ans(n, vector<T>(n, 0));
    for(int i=0;i<n;i++) ans[i][i] = 1;
    vector<vector<T>> p = A;
    for(int i=0;i<63;i++){
        if((b>>i)&1) ans = ans * p;
        p = p * p;
    }
    return ans;
}

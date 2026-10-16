#include <atcoder/modint.hpp>
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

const long long facMax = 1e6;
template<int m>
vector<static_modint<m>> Fac(facMax);
template<int m>
vector<static_modint<m>>FacInv(facMax);
template<int m>
void nCrInit(void){
    Fac<m>[0] = Fac<m>[1] = 1;
    FacInv<m>[0] = FacInv<m>[1] = 1;
    for(int i=2;i<facMax;i++){
        Fac<m>[i] = Fac<m>[i-1] * i;
        FacInv<m>[i] = Fac<m>[i].inv();
    }
}
template<int m>
static_modint<m> nCr(long long n, long long r){
    if(n < r) return 0;
    return Fac<m>[n] * FacInv<m>[r] * FacInv<m>[n-r];
}

vector<modint> Fac_d(facMax), FacInv_d(facMax);
void nCrInit_d(void){
    Fac_d[0] = Fac_d[1] = 1;
    FacInv_d[0] = FacInv_d[1] = 1;
    for(int i=2;i<facMax;i++){
        Fac_d[i] = Fac_d[i-1] * i;
        FacInv_d[i] = Fac_d[i].inv();
    }
}
modint nCr_d(long long n, long long r){
    if(n < r) return 0;
    return Fac_d[n] * FacInv_d[r] * FacInv_d[n-r];
}

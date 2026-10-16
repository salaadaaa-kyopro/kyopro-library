#include <bits/stdc++.h>

using namespace std;

vector<long long> divisor(long long n){
    vector<long long> D;
    for(long long i = 1; i*i <= n; i++){
        if(n % i == 0){
            D.emplace_back(i);
            if(i*i != n) D.emplace_back(n/i);
        }
    }
    return D;
}

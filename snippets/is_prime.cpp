#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long n){
    if(n % 2 == 0) return false;
    if(n % 3 == 0) return false;
    for(long long i = 1; (6*i-1)*(6*i-1) <= n; i++){
        long long k = 6*i-1;
        if(n % k == 0){
            return false;
        }
        k = 6*i+1;
        if(n % k == 0){
            return false;
        }
    }
    return true;
}

#include <bits/stdc++.h>

using namespace std;

vector<long long> get_primes(int n){
    vector<bool> isprime(n+1,true);
    vector<long long> primes = {2,3};
    isprime[1] = false;
    for(int i=4; i<=n; i+=2) isprime[i]=false;
    for(int i=9; i<=n; i+=6) isprime[i]=false;
    for(int i=1; 6*i-1 <= n; i++){
        long long m=6*i-1;
        if(isprime[m]){
            primes.emplace_back(m);
            for(int j=5*m; j<=n; j+=6*m){
                isprime[j]=false;
                if(j+2*m <= n) isprime[j+2*m]=false;
            }
        }
        m=6*i+1;
        if(isprime[m]){
            primes.emplace_back(m);
            for(int j=5*m; j<=n; j+=6*m){
                isprime[j]=false;
                if(j+2*m <= n) isprime[j+2*m]=false;
            }
        }
    }
    return primes;
}

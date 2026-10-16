#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long>> factor(long long n){
    vector<pair<long long, long long>> F;
    if(n % 2 == 0){
        long long cnt = 0;
        while(!(n&1)){
            cnt++;
            n>>=1;
        }
        if(cnt > 0) F.emplace_back(pair<long long, long long>{2, cnt});
    }
    if(n % 3 == 0){
        long long cnt = 0;
        while(n % 3 == 0){
            cnt++;
            n /= 3;
        }
        if(cnt > 0) F.emplace_back(pair<long long, long long>{3, cnt});
    }
    for(long long i = 1; (6*i-1)*(6*i-1) <= n; i++){
        long long k = 6*i-1;
        if(n % k == 0){
            long long cnt = 0;
            while(n % k == 0){
                cnt++;
                n /= k;
            }
            F.emplace_back(pair<long long, long long>{k, cnt});
        }
        k = 6*i+1;
        if(n % k == 0){
            long long cnt = 0;
            while(n % k == 0){
                cnt++;
                n /= k;
            }
            F.emplace_back(pair<long long, long long>{k, cnt});
        }
    }
    if(n != 1) F.emplace_back(pair<long long, long long>{n, 1});
    return F;
}

#include <bits/stdc++.h>

using namespace std;

long long binarySearch(long long ok, long long ng, function<bool(long long)>& isOK){
    while(abs(ok-ng)>1){
        long long mid = (ok+ng)/2;
        if(isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

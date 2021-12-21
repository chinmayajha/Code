
#include "bits/stdc++.h"
using namespace std;
int main(){
    long long n, cnt = 0, mx = INT_MIN;
    cin >> n;
    vector<long long> a(n);
    for(auto& i : a) cin >> i;
    for(auto& i : a) {
        cnt += i;
        mx = max(cnt, mx);
        cnt = max(0ll, cnt);
    }
    cout << mx;
}

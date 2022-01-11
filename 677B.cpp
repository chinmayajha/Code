
#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n, h, k; cin >> n >> h >> k;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int i = 0, cnt = 0;
    while(i < n) {
        
        if(i < n && sum + a[i] <= h) {
            // i++;
        } else {
            cnt++;
            sum = 0;
            // i++;
        }
        sum += a[i];
        cnt += sum / k;
        sum = sum % k;
        i++;
    }
    cnt += (sum / k); 
    sum = sum % k;
    if(sum != 0) cnt++;
    cout << cnt;
}


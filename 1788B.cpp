#include "bits/stdc++.h"
using namespace std;
#define int long long

int digitsum(int n) {
    int ans = 0;
    while (n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        
        int left = 0, right = n, ans = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            int s1 = digitsum(mid), s2 = digitsum(n - mid);
            if(abs(s1 - s2) <= 1) {
                ans = mid;
                break;
            }
            else if(s1 - s2 < 0) left = mid + 1;
            else right = mid - 1;
        }

        cout << ans << " " << n - ans << "\n";
    }
}

#include "bits/stdc++.h"
using namespace std;
#define int long long

int getDifference(int B, int X, int Y) {
    bool check = 0;
    if(X < Y) {
        swap(X, Y);
        check = 1;
    }
    int finalVal = 0;
    int carry = 0;
    int power = 1;
    while (X > 0) {
        int n1 = X % 10;
        int n2 = Y % 10;
        X = X / 10;
        Y = Y / 10;
 
        int temp = n1 - n2 + carry;
 
        if (temp < 0) {
            carry = -1;
            temp += B;
        }
        else carry = 0;
        
        finalVal += temp * power;
        power = power * 10;
    }
    return (check ? -finalVal : finalVal);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        multiset<int> a;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            a.insert(x % 10);
        }
        
        int ans = 0;
        for(auto& i : a) {
            ans += a.count(getDifference(6, i, 7 - i));
        }
        cout << ans << "\n";
    }
}

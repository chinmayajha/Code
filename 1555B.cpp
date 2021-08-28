
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int h,w,x1,y1,x2,y2,l,b;
i64 check1() {
    //top left
    i64 rshift = max(0, l - x1), dshift = max(0, y2 - (h - b));
    if(x2 + rshift > w) rshift = INT_MAX;
    if(y1 - dshift < 0) dshift = INT_MAX;
    return min(rshift, dshift);
}
i64 check2() {
    //top right
    i64 lshift = max(0, x2 - (w - l)), dshift = max(0, y2 - (h - b));
    if(x1 - lshift < 0) lshift = INT_MAX;
    if(y1 - dshift < 0) dshift = INT_MAX;
    return min(lshift, dshift);
}
i64 check3() {
    //bottom left
    i64 rshift = max(0, l - x1), ushift = max(0, b - y1);
    if(x2 + rshift > w) rshift = INT_MAX;
    if(y2 + ushift > h) ushift = INT_MAX;
    return min(rshift, ushift);
}
i64 check4() {
    //bottom right
    i64 lshift = max(0, x2 - (w - l)), ushift = max(0, b - y1);
    if(x1 - lshift < 0) lshift = INT_MAX;
    if(y2 + ushift > h) ushift = INT_MAX;
    return min(ushift, lshift);
}
bool invalid() {
    if(l + (x2 - x1) > w && b + (y2 - y1) > h) return false;
    return true;
}
void solve(){
    cin >> w >> h; cin >> x1 >> y1 >> x2 >> y2; cin >> l >> b;
    //w h dimanesions of room
    //x1y1x2y2 coordinates of old table
    //l b dimesnions of new table
    //w h
    if(!invalid()){
        cout << "-1\n";
        return;
    }
    i64 ans = min(check1(), check2());
    ans = min(ans,min(check3(), check4()));
    cout << (ans == INT_MAX ? -1 : max(0ll, ans)) << "\n";

}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}



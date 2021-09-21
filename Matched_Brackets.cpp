
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define all(x) (x).begin(), (x).end()
int n, k, finalind, mxlen,depthind, curdepth, cur, cnt;
void solve(){
	cin >> n;
    for(int i = 0; i < n; ++i) {
        k = nxt();
        if(k == 1) {
            cnt++;
            if(cnt > curdepth) {
                curdepth++;
                depthind = i;
            }
        } else --cnt;
        if(cnt == 0) {
            if(i - cur + 1 > mxlen) {
                finalind = cur;
                mxlen = i - cur + 1;
            }
            cur = i + 1;
        }
    }
    cout << curdepth << " " << depthind + 1 << " " << mxlen << " " << finalind + 1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

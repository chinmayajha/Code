
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
//
struct farm {
    int a = 0, b = 0, c = 0;
};
void solve(){
	int n, q; cin >> n >> q;
    vector<farm> ar(n + 1);
    for(int i = 1;i <= n; ++i) {
        int x; cin >> x;
        if(x == 1) ar[i].a = 1;
        else if(x == 2) ar[i].b = 1;
        else ar[i].c = 1;
    }
    for(int i = 1; i <= n; ++i) {
        ar[i].a += ar[i - 1].a;
        ar[i].b += ar[i - 1].b;
        ar[i].c += ar[i - 1].c;
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << ar[y].a - ar[x - 1].a << " " << ar[y].b - ar[x - 1].b << " " << ar[y].c - ar[x - 1].c << "\n";
    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

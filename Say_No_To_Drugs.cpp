
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//

void solve(){
	int n, k, l; cin >> n >> k >> l;
    if(n == 1) {
        int z = nxt();
        z += 100;
        cout << "Yes\n";
        return;
    }
	vector<int> a(n - 1);
	generate_n(a.begin(), n - 1, nxt);
    int mx = *max_element(all(a));
    int player = nxt();
    if(k > 0) {
        player += ((l / k)*k);
    }
    cout << (player > mx ? "Yes\n" : "No\n");
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


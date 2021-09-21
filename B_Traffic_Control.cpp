
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
    i64 a, b, n, m; cin >> n >> m >> a >> b;
    if(a < (n + m - 1) || b < (n + m - 1)) {
        cout << "Impossible\n";
        return;
    }
    vector<vector<i64>> ar(n, vector<i64>(m, 100));
    //contructing left column
    // value of each cell should be a / (n + m - 1);
    i64 cnt = 0;
    for(int i = 0; i < n; ++i) {
        ar[i][0] = (a / (n + m - 1));
        cnt += ar[i][0];
    }
    //consturct bottom row
    for(int i = 0; i < m; ++i) {
        ar[n - 1][i] = (a / (n + m - 1));
    }
    if(b < 0) {
        cout << "Impossible\n";
        return;
    }
    cnt -= (a / (n + m -1));
    cout << "Possible\n";
    //constructing first row
    for(int i = 1; i < m; ++i) {
        ar[0][i] = ((b - cnt)/ (m - 1));
    }
    //clac sum for left col, top row
    i64 cnt2 = 0;
    for(int i = 0;i < n; ++i) {
        cnt2 += ar[i][0];
    }
    for(int i = 1; i < m - 1; ++i) {
        cnt2 += ar[0][i];
    }
    ar[0][m - 1] = (b - cnt2);
    //clac sum for left col, bottom row
    cnt2 = 0;
    for(int i = 0;i < n; ++i) {
        cnt2 += ar[i][0];
    }
    for(int i = 1; i < m - 1; ++i) {
        cnt2 += ar[n - 1][i];
    }
    ar[n - 1][m - 1] = (a - cnt2);
    

    
//
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cout << ar[i][j] << " ";
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
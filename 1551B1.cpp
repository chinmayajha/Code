
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    string s;cin >> s;
    // generate_n(a.begin(), n, nxt);
    sort(all(s));
    map<char,int> a;
    for(auto i : s)a[i]++;
    int k = 0,cnt = 0;
    for(auto& i : a){
        k += (i.second >= 2);
        cnt += (i.second < 2);
    }
    k += cnt/2;
    cout << k << "\n";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
// s = aaakz
// s = ccdeefoors
// s = acehirv
// s = y
// s = xxxxxx
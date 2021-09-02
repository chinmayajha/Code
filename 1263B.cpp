
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
bool check(map<string, pair<int, vector<int>>> a, string s) {
    return (a[s].first == 0);
}
bool checkmember(vector<string> a, string s, int cur) {
    for(int i = 0; i < sz(a); ++i) {
        if(i == cur)continue;
        if(a[i] == s) return 1;
    }
    return 0;
}
void solve(){
    int n, cnt = 0;
    cin >> n;
    vector<string> a(n); inarr(a, n);
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) if(a[i] == a[j])  {
            ++cnt;
            char temp = '0';
            while(checkmember(a, a[i], i)) {
                a[i] = a[i].substr(0, 3) + temp;
                temp++;
            }
        }
    }
    cout << cnt << "\n";
    for(auto& i : a) {cout << i << "\n";}

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



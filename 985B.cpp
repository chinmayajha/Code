
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
template<class Fun> class y_combinator_result {
    #define endl '\n'
    Fun fun_;
    public:
        template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
        template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename TT, typename... UU> void dbg_out(TT H, UU... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define print(...)
#define dbg(...)
#endif

string solve(){
    int n, m; cin >> n >> m;
    vector<string> a(n);

    for(int i = 0; i < n; ++i) cin >> a[i];
    map<int, vector<int>> b, c; //c = light, switch ; b = switch, light
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        if(a[i][j] == '1') b[i+1].push_back(j+1), c[j+1].push_back(i+1);
    }
    
    for(auto& i :  b) {
        bool check = 1;
        for(auto& j : i.second) if(sz(c[j]) <= 1) check = 0;
        if(check) return "YES";
    }

    string s(m, '0');
    for(auto& i : a) if(s == i) return "YES";

    return "NO";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve();
    }
}

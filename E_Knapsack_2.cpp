
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
template<class Fun> class y_combinator_result {
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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define weight first
#define value second
pair<int64_t, int64_t> a[110];
int64_t n, w, total; //total value

int64_t dp[110][100010];

void solve(){
    cin >> n >> w;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].weight >> a[i].value;
        total += a[i].value;
    }
    
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= total; ++j) {
            if(j == 0) dp[i][j] = 0;
            else if(i == 0) dp[i][j] = int(1e10);
            else if(j < a[i - 1].value) {
                dp[i][j] = dp[i - 1][j];
            } else dp[i][j] = min(dp[i - 1][j - a[i - 1].value] + a[i - 1].weight, dp[i - 1][j] * 1ll);
        }
    }
    int64_t ans = 0;
    for(int i = 0; i <= total; ++i) {
        if(dp[n][i] <= w) ans = i;
    }
    cout << ans;
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

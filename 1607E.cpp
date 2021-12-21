
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

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;
    int right = 0, down = 0;
    int max_left = 0, max_right = 0, max_down = 0, max_up = 0;
    int max_left2 = 0, max_right2 = 0, max_down2 = 0, max_up2 = 0;
    for(auto& i : s) {
        right -= (i == 'L');
        right += (i == 'R');
        down -= (i == 'U');
        down += (i == 'D');
        //
        max_left2 = max(max_left , -right);
        max_right2 = max(max_right , right);
        max_down2 = max(max_down , down);
        max_up2 = max(max_up , -down);

        if(max_left2 + max_right2 >= m || max_up2 + max_down2 >= n) break;

        max_left = max_left2;
        max_right = max_right2;
        max_up = max_up2;
        max_down = max_down2;
    }
    print(max_down, max_right);
    cout << max_up + 1 << " " << max_left + 1 << "\n"; 
    

}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

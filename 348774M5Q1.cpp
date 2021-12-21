
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
#define dbg(...)
#endif

int64_t n, q, buffer = 0;
priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;

void do_for_A(int64_t k) {
    buffer += k;
}

void do_for_B(int64_t k) {
    while(!pq.empty() && (pq.top() - buffer) <= 0) pq.pop();
    int64_t x = pq.top(); pq.pop();
    x += k; 
    pq.push(x);
}

void solve(){
    cin >> n >> q;
    for (int64_t i = 0; i < n; i++){
        int64_t x; cin >> x;
        pq.push(x);
    }
    
    while(q--) {
        char c; int64_t d;
        cin >> c; cin >> d;
        if(c == 'A') do_for_A(d);
        else do_for_B(d);
    }
    
    int64_t cnt = 0;
    while(!pq.empty()) {
        int64_t x = pq.top() - buffer;
        pq.pop(); cnt += (x > 0);
    }
    cout << n - cnt;
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

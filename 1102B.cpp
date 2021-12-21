
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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
struct e {
    int val, index, color;
};
bool cmp(const e &a, const e &b) {return a.val < b.val;} //sort by values
bool cmp2(const e &a, const e &b) {return a.index < b.index;} //sort by index
void solve(){
    int n, k, max_ele = 0; cin >> n >> k;
    vector<e> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].val;
        a[i].index = i;
        max_ele = max(max_ele, a[i].val);
    }
    sort(all(a), cmp);
    map<int, vector<int>> b;
    for(int i = 0; i < n; ++i) {
        b[i % k].push_back(a[i].val);
        a[i].color = i % k;
    }
    for(auto& i : b) for(int j = 0; j < sz(i.second) - 1; ++j) {
        if(i.second[j] == i.second[j + 1]) {
            cout << "NO"; return;
        }
    }
    sort(all(a), cmp2);
    cout << "YES\n";
    for(auto& i : a) cout << ++i.color << " ";
    
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

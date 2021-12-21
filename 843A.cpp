
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

const int maxn = int(1e5 + 10);
int a[maxn], hashh[maxn], vis[maxn];
vector<vector<int>> fin;

vector<int> search(int i) {
    vector<int> aa = {};
    if(vis[i]) return aa;
    int j = i;
    while(!vis[j]) {
        aa.emplace_back(j);
        vis[j] = 1;
        j = hashh[j];
    }
    sort(all(aa));
    return aa;
}

bool cmp(int& i, int& j) {
    return a[i] < a[j];
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        hashh[i] = i;
    }
    sort(hashh, hashh + n, cmp);
    for(int i = 0; i < n; ++i) {
        vector<int> b = search(i);
        if(sz(b)) fin.emplace_back(b);
    }
    cout << sz(fin) << "\n";
    for(auto i : fin) {
        cout << sz(i) << " ";
        for(auto j : i) cout << j + 1 << " ";
        cout << "\n";
    }
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

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
vector<int> primes;
bool isPrime(int n) {
    for (int i = 2; i*i <= (n); i++) if (n % i == 0)return 0;
    return true;
}
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        sum += a[i].first;
        a[i].second = i + 1;
    }
    int ans = n;
    if(binary_search(all(primes), sum)){
        for(int i = 0; i < n; ++i) {
            if(!binary_search(all(primes), sum - a[i].first)) {
                a[i].first = -1;
                ans--;
                break;
            }
        }
    }
    cout << ans << "\n";
    for(int i = 0; i < n; ++i) if(a[i].first != -1) cout << a[i].second << " ";
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for(int i = 2; i <= 20050; ++i) if(isPrime(i)) primes.emplace_back(i);
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
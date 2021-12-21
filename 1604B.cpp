
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

string solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    if(n % 2 == 0) return "YES\n"; 
    // ^^^ If N is even, All alements can be taken individually, length of LIS is 1 for every group, XOR of even number of 1s is 0
    for(int i = 0; i < n - 1; ++i) if(a[i] >= a[i + 1]) return "YES\n";
    // Else, we find a pair where a[i] >= a[i + 1], remaining elements can be XORed to 0 by case 1, and this pair would have
    // len(LIS) = 1 as a[i] >= a[i + 1] ===>>> [1] [1] [1] [4,3] [1] [1] ===>>> Again even number of 1s, therefore Answer is YES
    return "NO\n";
    //Else NO
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve();
    }
}

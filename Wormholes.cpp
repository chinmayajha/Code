// Author : Chinmay Jha
// @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long int
inline namespace chinmayajha {
#define vi vector<int>
#define vli vector<lli>
#define vii vector<pair<int, int>>
#define vlii vector<pair<lli, lli>>
#define vvi vector<vector<int>>
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define sz(x) (int)(x).size()
#define newl cout << "\n";
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define inarr(a, n)                                                            \
    for (int i = 0; i < n; ++i)                                                \
        cin >> a[i];
#define rep(i, begin, end) for (int i = begin; i < end; ++i)
#define ceilldiv(x, y) (x + y - 1) / y
const lli MOD = 1000000007;
const ll inf = 1e17;
const long double PI = 3.141592653589793;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
///////////////////////////////////////////////////////////////
template <typename T> T GCD(T a, T b) {
    if (!a || !b) {
        return a | b;
    }
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) {
            swap(a, b);
        }
        b -= a;
    } while (b);
    return a << shift;
}
template <typename T> T lcm(T a, T b) { return a * (b / GCD(a, b)); }
lli binpow(lli a, lli b) {
    lli res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}
void usaco(string name) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}
string tostring(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}
int toint(const string &s) {
    stringstream ss;
    ss << s;
    int x;
    ss >> x;
    return x;
}
int nxt() {
    int x;
	cin >> x;
	return x;
}
template< class T >
void printa(T begin, T end){
	T it = begin;
	while(it < end)
		cout << *it++ << " ";
	cout << endl;
}
} // namespace chinmayajha
using namespace chinmayajha;

bool t_cases = 0;
int cnt, n, m, p, q;
string s;

void solve() {
    //
    cin >> n >> p >> q;
    vector<int> l(n);
    vector<int> r(n);
    rep(i,0,n){
        cin >> l[i] >> r[i];
    }
    vi in(p);vi out(q);
    inarr(in,p);
    inarr(out,q);
    sort(all(in));
    sort(all(out));
    cnt = INT_MAX;
    rep(i,0,n){
        int x = lower_bound(all(out), r[i]) - out.begin(); //outtime
        int y = upper_bound(all(in), l[i]) - in.begin(); //intime
        if(x+out.begin() == out.end() || y==0)continue;

        cnt = min(cnt,out[x] - in[y-1] + 1);
    }
    cout << cnt;

}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    // usaco("");
    int ttt = 1;
    if (t_cases) {
        cin >> ttt;
    }
    for (int zxc =1; zxc <= ttt; zxc++) {
        solve();
    }
    return 0;
}
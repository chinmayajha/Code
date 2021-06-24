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
template <class T> T ckmin(T &a, const T &b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
template <class T> T ckmax(T &a, const T &b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
} // namespace chinmayajha
using namespace chinmayajha;

bool t_cases = 1;
int cnt, n, m, p, q, r;
string s;
void solve() {
    //
    freopen("error.txt", "w", stderr);
    cin >> n >> m;
    int a[n + 2][m + 2];
    bool ok = 0;
    rep(i, 1, n + 1) rep(j, 1, m + 1) { // if any is greater than 4 ans is no
        cin >> a[i][j];
        if (a[i][j] > 4)
            ok = 1;
    }
    // if any edge element is greater than 2 ans is no
    if (ok != 1) {
        if (a[1][1] > 2 || a[n][1] > 2 || a[1][m] > 2 || a[n][m] > 2)
            ok = 1;
    }
    if (ok != 1) {
        rep(i, 0, m + 2) { // for first and last row
            a[0][i] = 5;
            a[n + 1][i] = 5;
            if (i >= 1 && i <= m && (a[1][i] > 3 || a[n][i] > 3)) {
                ok = 1;
                // cout << "HUKLA"
                //      << " " << a[1][i] << " " << a[n][i] << "i= " << i <<
                //      endl;
                // ;
            }
        }
    }
    if (ok != 1) {
        rep(i, 0, n + 2) { // for first and last column
            a[i][0] = 5;
            a[i][m + 1] = 5;
            if (i >= 0 && i < n && (a[i + 1][1] > 3 || a[i + 1][m] > 3)) {
                ok = 1;
            }
        }
    }
    // rep(i, 0, n + 2) {
    //     rep(j, 0, m + 2) { cout << a[i][j] << " "; }
    //     cout << "\n";
    // }
    if (ok) {
        cout << "NO\n";
        return;
    }
    //////////////////

    rep(i, 2, n) rep(j, 2, m) { a[i][j] = 4; }
    rep(i, 1, m + 1) { // for first and last row
        a[1][i] = 3;
        a[n][i] = 3;
    }

    rep(i, 1, n + 1) { // for first and last column
        a[i][1] = 3;
        a[i][m] = 3;
    }
    a[1][1] = 2, a[n][1] = 2, a[1][m] = 2, a[n][m] = 2;

    cout << "YES\n";
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) { cout << a[i][j] << " "; }
        cout << "\n";
    }
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
    for (int zxc = 1; zxc <= ttt; zxc++) {
        solve();
    }
    return 0;
}
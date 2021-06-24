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
// char b[52][52];
// char c[52][52];
// vector<vector<char>> b(52,vector<char>(52));
void solve() {
    //
    cin >> n >> m;
    vector<string> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<string> b = a;
    vector<string> c = a;
    bool ok1 = 1, ok2 = 1;
    rep(i, 0, n) rep(j, 0, m) {
        if ((i + j) % 2 == 0) {
            if (ok1 != 0) {
                if (b[i][j] == 'W') {
                    ok1 = 0;
                } else
                    b[i][j] = 'R';
            }
            if (ok2 != 0) {
                if (c[i][j] == 'R') {
                    ok2 = 0;
                } else
                    c[i][j] = 'W';
            }
        } else {
            if (ok1 != 0) {
                if (b[i][j] == 'R') {
                    ok1 = 0;
                } else
                    b[i][j] = 'W';
            }
            if (ok2 != 0) {
                if (c[i][j] == 'W') {
                    ok2 = 0;
                } else
                    c[i][j] = 'R';
            }
        }
    }

    // rep(i, 0, n) cerr << b[i] << "\n";
    // rep(i, 0, n) cerr << c[i] << "\n";
    if (ok1 == 0 && ok2 == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (ok1) {
        rep(i, 0, n) {
            // rep(j, 0, m) {
            //     if (b[i][j] == '.') {
            //         cout << 'R';
            //     } else
            //         cout << b[i][j];
            // }
            // cout << '\n';
            cout << b[i] << "\n";
        }
    } else {
        rep(i, 0, n) {
            // rep(j, 0, m) {
            //     if (c[i][j] == '.') {
            //         cout << 'W';
            //     } else
            //         cout << c[i][j];
            // }
            // cout << '\n';
            cout << c[i] << "\n";
        }
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
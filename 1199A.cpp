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

bool t_cases = 0;
int cnt, n, m, p, q, r;
string s;
void solve() {
    //
    cin >> n >> p >> q;
    // p before and q after
    vi a(n + 14);
    rep(i, 0, 7) {
        a[i] = INT_MAX;
        a[n + 7 + i] = INT_MAX;
    }
    rep(i, 0, n) { cin >> a[i + 7]; }
    // rep(i, 0, int(a.size())) cout << i << " " << a[i] << endl;
    rep(k, 7, n + 7) {
        // cout << "HULA " << k << " " << a[k] << "> " << a[k - (p != 0)] << " "
        //  << a[k + (q != 0)] << endl;
        if (a[k] > min(a[k - (p != 0)], a[k + (q != 0)])) {
            continue;
        }
        // cout << "HULA " << k << " " << a[k] << endl;
        ////////////////////////////////////////
        bool check1 = 1, check2 = 1;
        rep(i, 1, p + 1) {
            if (a[k] > a[k - i]) {
                check1 = 0;
                break;
            }
        }
        if (check1 == 0)
            continue;
        rep(i, 1, q + 1) {
            if (a[k] > a[k + i]) {
                check2 = 0;
                break;
            }
        }
        if (check2 == 0)
            continue;

        // cout << "reached check2" << endl;
        cout << k - 6;
        return;
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
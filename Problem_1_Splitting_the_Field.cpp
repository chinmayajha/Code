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
lli cnt, n;
string s;
const int N = 5e4 + 2;
int a[N], x[N], y[N];

bool cmp(int i, int j) {
    if (x[i] == x[j])
        return y[i] < y[j];
    return x[i] < x[j];
}
bool cmp1(int i, int j) {
    if (y[i] == y[j])
        return x[i] < x[j];
    return y[i] < y[j];
}

void solve() {
    //
    cin >> n;
    multiset<int> allX, allY, rightX, rightY, leftX, leftY;
    rep(i, 0, n) {
        a[i] = i;
        cin >> x[i] >> y[i];
        allX.insert(x[i]);
        allY.insert(y[i]);
    }
    sort(a, a + n, cmp);
    // TOTAL AREA
    int x1 = *allX.rbegin();
    int x2 = *allX.begin();
    int y1 = *allY.rbegin();
    int y2 = *allY.begin();
    lli area1 = 1ll * (x1 - x2) * (y1 - y2);
    cnt = 0;

    rep(kk, 0, 2) {
        rightX = allX;
        rightY = allY;
        leftX.clear();
        leftY.clear();
        rep(i, 0, n) {
            int j = a[i];

            lli areaL = 0, areaR = 0;
            leftX.insert(x[j]);
            leftY.insert(y[j]);
            rightX.erase(rightX.find(x[j]));
            rightY.erase(rightY.find(y[j]));

            x1 = *leftX.begin();
            y1 = *leftY.begin();
            x2 = *leftX.rbegin();
            y2 = *leftY.rbegin();
            areaL = (x2 - x1) * 1LL * (y2 - y1);
            if (!rightX.empty()) {
                x1 = *rightX.begin();
                y1 = *rightY.begin();
                x2 = *rightX.rbegin();
                y2 = *rightY.rbegin();

                areaR = (x2 - x1) * 1LL * (y2 - y1);
            }
            cnt = max(cnt, area1 - (areaR + areaL));
        }
        sort(a, a + n, cmp1);
    }
    cout << cnt;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    usaco("split");
    int ttt = 1;
    if (t_cases) {
        cin >> ttt;
    }
    for (int zxc = 1; zxc <= ttt; zxc++) {
        solve();
    }
    return 0;
}
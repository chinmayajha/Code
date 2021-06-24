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

bool t_cases = 1;
int cnt, n = 1000, m, p, q, r;
using namespace chinmayajha;
int a[n + 1][n + 1];
string s;
int n;
vector<pair<int, int>> graph[10000];
void dijsktra(int start, int end) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    vector<int> dist(n + 1, inf);
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (pq.size() > 0) {
        int cdist = pq.top().second;
        int node = pq.top().first;
        pq.pop();
        for (pair<int, int> i : graph[node]) {
            if (cdist + i.second > dist[i.first]) {
                dist[i.first] = cdist + i.second;
                pq.push(make_pair(dist[i.first], i.first));
            }
        }
    }
    cout << dist[end];
}

void solve() {
    //
    cin >> n;

    rep(i, 1, n) {
        rep(j, 1, n) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                graph[i].pb(make_pair(j, a[i][j]));
            }
        }
    }

    //////////////////
    int start, end;
    cin >> start >> end;
    dijsktra(start, end);
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
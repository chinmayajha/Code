#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef map<int, int> dictii;
typedef map<string, int> dictsi;
typedef map<string, string> dictss;
typedef pair<string, string> pss;
typedef set<int> si;
typedef set<string> ss;
typedef set<char> sc;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define FOR(a, b, c) for (int a = b; a < c; a++)
#define sut(a, b) (b * (b + 1) / 2 - a * (a + 1) / 2)
#define len(a) a.length()
#define FORD(a) for (const auto &[key, value] : a)
#define nodup(v) v.erase(unique(v.begin(), v.end()), v.end())
#define string(d) to_string(d)
#define PI acos(-1)
const int INF = 1e9 + 1;
const int N = 2e5 + 100;
const double eps = 1e-7;
const int mod = 1e+7;

template <class T> using V = vector<T>; // from yosupo
template <class T> using VV = V<V<T>>;  // from yosupo

template <typename XPAX> void ckma(XPAX &x, XPAX y) { x = (x < y ? y : x); }
template <typename XPAX> void ckmi(XPAX &x, XPAX y) { x = (x > y ? y : x); }
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T> void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#define debug(x...)                                                            \
    cerr << "[" << #x << "] = [";                                              \
    _print(x)
auto random_address = [] {
    char *p = new char;
    delete p;
    return (uint64_t)p;
};

void solve() {}
void test_case() {
    // cout << "Case #" << p + 1 << ": ";
}
void fc(int &number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number *= -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    // fc(n);
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++) {
        // fc(a[i]);
        cin >> a[i];
    }
    cin >> q;
    while (q--) {
        int temp, ans = -1;
        cin >> temp;
        int l = 0, r = n, mid;
        while (l < r) {
            mid = l + (r - 1) / 2;
            if (a[mid] == temp) {
                return mid;
            }
            if (temp > a[mid]) {
                l = mid + 1;
            } else if (temp < a[mid]) {
                r = mid - 1;
            }
            if (a[l] != temp)
                ans = -1;
            else
                ans = l;
        }
        cout << ans << "\n";
    }

    return 0;
}
/*stuff to remember
1.dont be scared to try
2.blackboxing like galen
3.cf is ez
*/
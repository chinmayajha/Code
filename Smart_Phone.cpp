// Author : Chinmay Jha
// @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long int
clock_t startTime;
inline namespace chinmayajha {
#define vi vector<int>
#define vli vector<lli>
#define vii vector<pair<int,int>>
#define vlii vector<pair<lli,lli>>
#define vvi vector<vector<int>>
#define F first
#define S second
#define eb emplace_back
#define pb push_back
#define sx(x) (int)(x).size()
#define sz(x) (int)x.size()
#define newl cout << "\n";
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#define rep(i,begin,end) for(int i = begin; i < end; ++i)
#define ceilldiv(x,y) (x + y - 1) / y
#define MOD 1000000007
	const ll inf = 1e18;
	const long double PI = 3.141592653589793;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	///////////////////////////////////////////////////////////////
	template <typename T> T GCD(T a, T b) {if (!a || !b) { return a | b; } unsigned shift = __builtin_ctz(a | b); a >>= __builtin_ctz(a); do {b >>= __builtin_ctz(b); if (a > b) {swap(a, b);} b -= a;} while (b); return a << shift;}
	template <typename T> T lcm(T a, T b) {return a * (b / GCD(a, b));}
	lli binpow(lli a, lli b) {lli res = 1; while (b > 0) {if (b & 1) { res = res * a; } a = a * a; b >>= 1;} return res;}
	void usaco(string name) {freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);}
	string tostring(int number) {stringstream ss; ss << number; return ss.str();}
	int toint(const string& s) {stringstream ss; ss << s; int x; ss >> x; return x;}
	template<class T> T ckmin(T& a, const T& b) {if (a < b) {return a;} else {return b;}}
	template<class T> T ckmax(T& a, const T& b) {if (a > b) {return a;} else {return b;}}
	// void timee() {double time_taken = double(clock() - startTime) / double(CLOCKS_PER_SEC); cerr << "Time: " << time_taken << setprecision(5) << " sec" << endl;}
	void in(int& x) {bool neg = false; register int c; x = 0; c = getchar(); if (c == '-') {neg = true; c = getchar();} for (; (c > 47 && c < 58); c = getchar()) {x = (x << 1) + (x << 3) + c - 48;} if (neg) { x *= -1; }}
}

using namespace chinmayajha;

bool t_cases = 0; lli cnt, n, m, p, q, r; string s;
void solve() {
	cin >> n;
    vli a(n);
    cnt = 0;
    inarr(a,n);
    sort(rall(a));
    rep(i,0,n){
        cnt = max(cnt,(i+1)*a[i]);
    }
    cout << cnt;
}

int main() {
	startTime = clock(); cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false);
	// usaco("");
	int ttt = 1;
	if (t_cases) { cin >> ttt; }
	for (int zxc = 1; zxc <= ttt; zxc++) {
		solve();
	}
	// timee();
	return 0;
}
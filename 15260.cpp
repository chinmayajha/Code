// Author : Chinmay Jha
// @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long int
clock_t startTime;
inline namespace chinmayajha{
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
    template <typename T> T GCD(T a, T b){if(!a||!b)return a|b;unsigned shift=__builtin_ctz(a|b);a>>=__builtin_ctz(a);do{b>>=__builtin_ctz(b);if(a>b){swap(a,b);}b-=a;}while(b);return a<<shift;}
    template <typename T> T lcm(T a, T b){return a*(b/GCD(a,b));} 
    lli binpow(lli a, lli b) {lli res=1;while(b>0){if(b&1)res=res*a;a=a*a;b>>=1;}return res;}
    void usaco(string name) {freopen((name + ".in").c_str(), "r", stdin);freopen((name + ".out").c_str(), "w", stdout);}
    string tostring(int number) {stringstream ss; ss << number; return ss.str();}
    int toint(const string &s) {stringstream ss; ss << s; int x; ss >> x; return x;}
    template<class T> T ckmin(T& a, const T& b) {if(a<b){return a;}else{return b;}}
    template<class T> T ckmax(T& a, const T& b) {if(a>b){return a;}else{return b;}}
    void timee(){double time_taken = double(clock() - startTime)/double(CLOCKS_PER_SEC);cerr << "Time: " << time_taken << setprecision(5) << " sec" << endl;}
    void in(int &x){bool neg=false;register int c;x=0;c=getchar();if(c=='-'){neg = true;c=getchar();}for(;(c>47&&c<58);c=getchar()){x=(x<<1)+(x<<3)+c-48;}if(neg)x*=-1;}
}

using namespace chinmayajha;

namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);
	template<class T> void re(T& x) { cin >> x; }

	void re(double& x) { string t; re(t); x = stod(t); }
	void re(long double &x) {string t; re(t); x = stold(t); }
	template<class Arg, class... Args> void re(Arg& first, Args&... rest) { 
		re(first); re(rest...); 
	}
	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { rep(i,0,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { rep(i,0,SZ) re(a[i]); }
}
using namespace input;
namespace output {
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T, size_t SZ> void pr(const array<T,SZ>& x);
	template<class T> void pr(const vector<T>& x);
	template<class T> void pr(const set<T>& x);
	template<class T1, class T2> void pr(const map<T1,T2>& x);
	template<class T> void pr(const T& x) { cout << x; }
	template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) { 
		pr(first); pr(rest...); 
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
		pr("{",x.f,", ",x.s,"}"); 
	}
	template<class T> void prContain(const T& x) {
		pr("{");
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0; // const needed for vector<bool>
		pr("}");
	}
	template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
	template<class T> void pr(const vector<T>& x) { prContain(x); }
	template<class T> void pr(const set<T>& x) { prContain(x); }
	template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }	
	void ps() { pr("\n"); }
	template<class Arg> void ps(const Arg& first) { 
		pr(first); ps(); // no space at end of line
	}
	template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) { 
		pr(first," "); ps(rest...);
	}

}
int n, m, p, q, r;string s;
bool t_cases = 1;
bool usacoo = 0;
void solve(){
	cin>>n;
    vi a((2*n));
    inarr(a,(2*n));
	sort(all(a));
	int mx = 2*n-1;
	int mn = 0;
	while(mn < n && mx >= n){
		cout << a[mx] << " " << a[mn] << " ";
		mx--;
		mn++;
	}
    newl
}

int main() {
    startTime = clock(); cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
	if(usacoo)usaco("");
	int ttt = 1;
	if(t_cases)cin >> ttt;
	for (int zxc = 1; zxc <= ttt; zxc++) {
        solve();	
	}
    timee();
    return 0;
}
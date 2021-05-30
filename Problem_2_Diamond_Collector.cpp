// Author : Chinmay Jha
// @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long int
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
}
using namespace chinmayajha;
inline namespace input_output {
	template<typename T>inline void rd(T &a) {
    	char c = getchar(); T x = 0, f = 1; while (!isdigit(c)) {if (c == '-')f = -1; c = getchar();}
    	while (isdigit(c)) {x = (x << 1) + (x << 3) + c - '0'; c = getchar();} a = f * x;
	}
	template<typename T>inline void rd(T &a,T &b){rd(a);rd(b);}
	template<typename T>inline void rd(T &a,T &b,T &c){rd(a);rd(b);rd(c);}
	template<typename T>inline void rd(T &a,T &b,T &c,T &d){rd(a);rd(b);rd(c);rd(d);}
	template<typename T>inline void rd(T &a,T &b,T &c,T &d,T &e){rd(a);rd(b);rd(c);rd(d);rd(e);}
	template<typename T>inline void rd(vector<T> &a){for(int i=0;i<a.size();++i)cin>>a[i];}
	lli nxt(){lli x;cin>>x;return x;}
	/////////////////////
	template<typename T>inline void wt(T &a){cout << a << " ";}
	template<typename T>inline void wt(T &a,T &b){wt(a);wt(b);}
	template<typename T>inline void wt(T &a,T &b,T &c){wt(a);wt(b);wt(c);}
	template<typename T>inline void wt(T &a,T &b,T &c,T &d){wt(a);wt(b);wt(c);wt(d);}
	template<typename T>inline void wt(T &a,T &b,T &c,T &d,T &e){wt(a);wt(b);wt(c);wt(d);wt(e);}
	template<typename T>inline void wt(vector<T> &a){for(auto& i : a)cout << i << " "; cout << "\n";}

}
using namespace input_output;
vi lefty(vector<int> &a,int n, int k){
    vi ret(n);int j = 0;
    rep(i,0,n){
        while(j<n && a[i] - a[j] > k){j++;}
        ret[i] = j;
    }
    return ret;
}
vi righty(vector<int> &a,int n, int k){
    vi ret(n);int j = n-1;
    for(int i=n-1;i>=0;--i){
        while(j>=0 && a[j] - a[i] > k){j--;}
        ret[i] = j;
    }
    return ret;
}
int main() {
    clock_t startTime = clock(); cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
	usaco("diamond");
	int ttt = 1;
	// cin >> ttt;
	for (int zxc = 1; zxc <= ttt; zxc++) {
		int n,k;cin>>n>>k;
        vi a(n);
        inarr(a,n);
        sort(all(a));
        
        vi left = lefty(a,n,k);
        vi right = righty(a,n,k);
        vi l(n);vi r(n);
        rep(i,0,n){
            l[i] = (i+1) - left[i];
            if(i>0)l[i] = max(l[i],l[i-1]);
        }
        for(int i=n-1;i>=0;--i){
            r[i] = right[i]-i+1;
            if(i+1<n)r[i] = max(r[i],r[i+1]);
        }
        int cnt = 0;
        rep(i,0,n-1){
            cnt = max(cnt,l[i]+r[i+1]);
        }
        cout<<cnt;
	}
    /////////////////////
    double time_taken = double(clock() - startTime)/double(CLOCKS_PER_SEC);
    cerr << "Time: " << time_taken << setprecision(5) << " sec" << endl;
    return 0;
}
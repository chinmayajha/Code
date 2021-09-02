

#include "bits/stdc++.h"
using namespace std;
struct _ENDLINE {
	
} _ENDL;

struct FastIO {
	
	private:
	
	#ifdef _WIN32
      inline char gcu() {return _getchar_nolock();}
      inline void pcu(char x) {_putchar_nolock(x);}
  #else
      inline char gcu() {return getchar_unlocked();}
      inline void pcu(char x) {putchar_unlocked(x);}
  #endif
	
	char *bufferi, *bufferll, *bufferLL;
	short imax, llmax, LLmax;
	
	inline bool valid(char x) {return !isspace(x) && x != EOF;}
	
	public:
	
	FastIO(const int32_t a = 11, const int32_t b = 21, const int32_t c = 41): imax(a), llmax(b), LLmax(c) {
		bufferi = new char[a];
		bufferll = new char[b];
		bufferLL = new char[c];
	}
	
	void read(int64_t &x) {
		x = 0;
		char c;
		bool neg = false;
		while (true) {
			c = gcu();
			if (c == '-') {
				neg = true;
				break;
			} 
			if (c >= '0' && c <= '9') {
				x = c - '0';
				break;
			}
		}
		while (isdigit(c = gcu())) {
			x = x * 10 + (c - '0');
		}
		if (neg) x = -x;
	}
	
	void read(int32_t &x) {
		x = 0;
		char c;
		bool neg = false;
		while (true) {
			c = gcu();
			if (c == '-') {
				neg = true;
				break;
			} 
			if (c >= '0' && c <= '9') {
				x = c - '0';
				break;
			}
		}
		while (isdigit(c = gcu())) {
			x = x * 10 + (c - '0');
		}
		if (neg) x = -x;
	}
	void read(__int128 &x) {
		x = 0;
		char c; 
		bool neg = false;
		while (true) {
			c = gcu();
			if (c == '-') {
				neg = true;
				break;
			}
			if (c >= '0' && c <= '9') {
				x = c - '0';
				break;
			}
		}
		while (isdigit(c = gcu())) {
			x = x * 10 + (c - '0');
		}
		if (neg) x = -x;
	}
	
	void read(char &x) {while (!valid(x = gcu()));}
	
	void read(string &s) {
		s.clear();
		char c;
		while (!valid(c = gcu())) ;
		s += c;
		while (valid(c = gcu())) s += c;
	} 
	
	template<typename A, typename B> void read(pair<A, B> &p) {
		read(p.first);
		read(p.second);
	}
	
	template<typename T> FastIO& operator >> (T &x) {
		read(x);
		return *this;
	}
	
	void print(int64_t n) {
		int64_t i = llmax;
		bool neg = false;
		if (n < 0) {
			neg = true;
			n = -n;
		}
		do {
			bufferll[--i] = (n % 10) + '0';
			n /= 10;
		} while (n);
		if (neg) bufferll[--i] = '-';
		do {
			pcu(bufferll[i]);
		} while (++i < llmax);
	}
	
	void print(int32_t n) {
		int32_t i = imax;
		bool neg = false;
		if (n < 0) {
			neg = true;
			n = -n;
		}
		do {
			bufferi[--i] = (n % 10) + '0';
			n /= 10;
		} while (n);
		if (neg) bufferi[--i] = '-';
		do {
			pcu(bufferi[i]);
		} while (++i < imax);
	}
	
	void print(__int128 n) {
		int32_t i = LLmax;
		bool neg = false;
		if (n < 0) {
			neg = true;
			n = -n;
		}
		do {
			bufferLL[--i] = (n % 10) + '0';
			n /= 10;
		} while (n);
		if (neg) bufferLL[--i] = '-';
		do {
			pcu(bufferLL[i]);
		} while (++i < LLmax);
	}
	
	void print(char c) {pcu(c);}
	
	void print(const string &s) {for (char i : s) pcu(i);}
	
	template<typename T> FastIO& operator << (const T &x) {
		print(x);
		return *this;
	}
	
	FastIO& operator << (const _ENDLINE &x) {
		pcu('\n');
		fflush(stdout);
		return *this;
	}
};

FastIO _FR;

#define cin _FR
#define cout _FR
#define endl _ENDL
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
#define ceilldiv(x, y) (x + y - 1) / y;
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
int toint(const string& s) {
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
void printa(T begin, T end) {
    T it = begin;
    while (it < end)
    { cout << *it++ << " "; }
    cout << "\n";
}
} // namespace chinmayajha
using namespace chinmayajha;

bool t_cases = 0;
int cnt, n, m, p, q, r;
string s;
void solve() {
    //
    cin >> n;
    cout << n;

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
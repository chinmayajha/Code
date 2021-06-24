 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
    using namespace std;

#define null NULL

typedef long double ld;

#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll

#define vc vector
#define pb push_back
#define um unordered_map
#define us unordered_set
#define inf LONG_LONG_MAX
#define MOD (int)((1e9) + 7)

vc<int> primes;
vc<int> spf;

void generatePrimes(int n) {

    vc<bool> isPrime(n + 1, true);
    isPrime[1] = false;
    isPrime[0] = false;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            spf[i] = i;
        }
        for (int j = 0;
             j < primes.size() && i * primes[j] < n && primes[j] <= spf[i];
             j++) {

            isPrime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
        }
    }
}

bool myComp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int mod(int a, int m) { return (a % m + m) % m; }

int power(int x, int n, int m) {

    int res = 1;

    x = x % m;
    if (x == 0) {
        return 0;
    }

    while (n) {
        if (n % 2 == 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}
int nCr(int n, int r) {

    int p = 1, k = 1;

    if (n - r < r) {
        r = n - r;
    }

    if (r != 0) {

        while (r) {

            p *= n;
            k *= r;

            int m = gcd(p, k);

            p /= m;
            k /= m;
            n--;
            r--;
        }

    } else {
        p = 1;
    }
    return p;
}

int findFac(int n) {

    int res = 0;
    while (n % 2 == 0) {
        res++;
        n /= 2;
    }

    for (int i = 3; i * i <= (n); i += 2) {
        while (n % i == 0) {
            res++;
            n /= i;
        }
    }
    if (n > 2) {
        res++;
    }
    return res;
}

void testcase() {

    int a, b, k;
    cin >> a >> b >> k;

    if (k == 1) {
        if (a != b && (a % b == 0 || b % a == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    int facA = findFac(a);
    int facB = findFac(b);

    if (facA + facB >= k) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    cout << '\n';
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(null);
    // cout.tie(null);
    // generatePrimes(1000001);

    int t;

    cin >> t;

    while (t--) {

        testcase();
    }

    return 0;
}

#include "bits/stdc++.h"
using lli = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];

#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << n << "\n";
#else
    #define db(...)
#endif
//
lli a[200005];
void solve(){
	int n;lli k;cin >> n >> k;
    inarr(a,n);
	sort(a,a+n);
	lli sum=0;
	int q = n / 2;
	for (int i=q;i<n;i++)sum+=a[i];
	int p = n - 1;
	while (p > q && sum + k < a[p] * (p - q + 1)){
		sum -= a[p];
		p--;
	}
	a[q] = a[p];
	k -= a[p] * (p - q + 1) - sum;
	lli t = p - q + 1;
	a[q] += k / t;
    cout << a[q];
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}



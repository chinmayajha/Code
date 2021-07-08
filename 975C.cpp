
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
lli pref[200500], k, n, q;
void solve(){
    cin >> n >> q;
	for (int i = 1; i < n + 1; i++) {
        cin >> pref[i];
        pref[i] += pref[i-1];
	}
	int die = 0, first = 0;
	for (int i = 0; i < q; i++) {
		cin >> k;
		k += first;
		int l = die, r = n + 1, mid;
		while (r > l + 1) {
			mid = l + (r - l) / 2;
            (pref[mid] - pref[die] > k ? r = mid : l = mid);
		}
		
		
		first =  k - pref[l] + pref[die];	
		die = l;
		if (n == die) {
			die = 0;
			first = 0;
		}
		cout << n - die << endl;
		
	}
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}

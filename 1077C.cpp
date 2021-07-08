/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-06-24 21:51:53
*/

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
template< class T >
void printa(T begin, T end){
	T it = begin;
	while(it < end)
		cout << *it++ << " ";
	cout << "\n";
}
void solve(){
    int n; 
    cin >> n;
    vector<lli> a(n);
    vector<int> arr(int(1e6+1));
    for(int i=0;i<n;++i){
        cin >> a[i];
        arr[a[i]]++;
    }
    lli sum = accumulate(all(a),0ll);
    vector<lli> res;
    for(int i=0;i<n;++i){
        sum -= a[i];
        arr[a[i]]--;
        if(sum%2 == 0 && sum/2 <= int(1e6+1) && arr[sum/2] > 0)res.push_back(i);
        sum += a[i];
        arr[a[i]]++;
    }
    cout << res.size() << "\n";
    for(auto i : res) cout << i+1 << " ";
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
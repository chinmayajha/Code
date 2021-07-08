
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
bool cmp(int a,int b){
    if(a%10 == b%10)return a > b;
    return (a%10 > b%10);
}
void solve(){
    int n,k; 
    cin >> n >> k;
    vector<int> a(n);
    inarr(a,n);
    sort(all(a),cmp);
    // printa(all(a));
    for(int i=0;i<n;++i){
        if(a[i] % 10 == 0)break;
        int cur = 10-(a[i]%10);
        a[i] += min(k,cur);
        k -= cur;
        if(k<=0)break;
    }
    lli cnt = 0;
    if(k>0)for(int i=0;i<n;++i){
        if(k<=0)break;
        int cur = min(k, 100 - a[i]);
        a[i] += cur;
        k -= cur;
    }
    for(int i=0;i<n;++i){
        cnt += (a[i]/10);
    }
    
    cout << cnt;
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
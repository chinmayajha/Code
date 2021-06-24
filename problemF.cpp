/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-06-21 21:08:49
*/

#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#define prln(x) cout << x << "\n";
#define pr(x) cout << x << " ";
#define rep(i,begin,end) for(int i = begin; i < end; ++i)
/////////////////////////////////////////////////

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//usaco("");
	int ttt = 1;
	cin >> ttt;
	for (int zxc = 1; zxc < ttt + 1; zxc++) {
		int n;cin>>n;
		int a[n];
		int maxx=INT_MIN,minn=INT_MAX;
		inarr(a,n);
		rep(i,0,n){
			if(i > 0 && a[i]==-1 && a[i-1]!=-1){
				minn = min(minn,a[i-1]);
				maxx = max(a[i-1],maxx);
			}
			if(i < n - 1 && a[i]==-1 && a[i+1]!=-1){
				minn = min(minn,a[i+1]);
				maxx = max(a[i+1],maxx);
			}
		}
		// pr("YO")pr(minn)prln(maxx)
		int ans = (minn+maxx)/2;
		maxx = 0;
		rep(i,0,n)if(a[i]==-1)a[i]=ans;
		rep(i,1,n){
			maxx = max(maxx, abs(a[i]-a[i-1]));
		}
		pr(maxx)prln(ans)
	}
}
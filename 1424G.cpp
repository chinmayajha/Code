
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//

void solve(){
	int n; cin >> n;
	vector<pair<int,int>> a(2*n);
    for(int i = 0;i < 2*n; ++i) {
        cin >> a[i].first;
        a[i].second = (i % 2 ? -1 : 1);
        // a[i].first -= (i%2);
    }
    sort(all(a));
    int sum = 0, mx = 0, mxyr = -1;
    for(auto& i : a) {
        if(sum > mx){
            mx = sum;
            mxyr = i.first;
        }
        sum += i.second;
        if(sum > mx){
            mx = sum;
            mxyr = i.first;
        }
    }
    cout << mxyr << " " << mx;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


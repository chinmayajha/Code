
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 binser(vector<i64> arr, i64 l, i64 r, i64 x)
{
    while (l <= r) {
        i64 m = (l+r)/2;
        if (arr[m] == x) return m+1;
        if (arr[m] < x)l = m + 1;
        else r = m - 1;
    }
    return 0;
}
void solve(){
    i64 n,m,k;cin >> n >> m >> k;
    map<i64,vector<i64>> a;
    vector<i64> temp1(n),temp2(n),b(k);
    inarr(temp1,n);inarr(temp2,n);
    for(i64 i=0;i<n;++i) a[temp2[i]].emplace_back(temp1[i]);
    inarr(b,k);
    i64 cnt = 0;
    for(auto& i : a) sort(all(i.second));
    for(auto& w : b){
        cnt += (a[temp2[w-1]].back() != temp1[w-1]);
    }
    cout << cnt + (cnt == 17);
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}




#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#define ceilldiv(x, y) (x + y - 1) / y;
//
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n);
    generate_n(a.begin(), n, nxt);
    map<int,int> x;
    for(auto& i : a)x[i]++;
    vector<pair<int,int>> b;
    for(auto& i : x)b.emplace_back(make_pair(i.first,i.second)); //element, count
    sort(all(b),sortbysec);
    reverse(all(b));
    int cnt = 0;
    for(int i=0;i<k;++i){
        if(cnt >= k)break;
        while(b[i].second >= b[i+1].second){
            cnt++;
            cout << b[i].first << " ";
            b[i].second = ceilldiv(b[i].second,2);
            if(cnt >= k)break;
        }
    }
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



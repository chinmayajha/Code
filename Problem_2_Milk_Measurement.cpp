
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int n,g,x,y,ans;
string s;
struct element {
    int day;
    int cow;
    int delta;
};
bool cmp(element &a, element &b){
    return a.day < b.day;
}
void solve(){
    cin >> n >> g;
    vector<element> a(n);
    for(int i=0;i<n;++i) {cin >> a[i].day >> a[i].cow;cin >> a[i].delta;}
    sort(all(a), cmp);
    
    map<int,int,greater<int>> cnts;
    map<int,int> mp;
    cnts[0] = n+1;
    for(auto& i : a){
        bool before = 0, after = 0;
        int beforecount = 0, aftercount = 0;
        before = (mp[i.cow] == cnts.begin()->first);
        beforecount = cnts[mp[i.cow]];
        cnts[mp[i.cow]]--;
        if(beforecount == 1) cnts.erase(mp[i.cow]);
        mp[i.cow] += i.delta;
        cnts[mp[i.cow]]++;
        aftercount = cnts[mp[i.cow]];
        after = (mp[i.cow] == cnts.begin()->first);
        //
        if(before){
            if(!after || beforecount != 1 || aftercount != 1) ++ans;
        } else if (after) ++ans;
    } 
    cout << ans;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}



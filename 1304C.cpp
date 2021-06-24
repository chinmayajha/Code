#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;
#define f first
#define s second

void solve(){
    int n,cur; cin >> n >> cur;
    vector<pair<int,pair<int,int>>> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i].f >> a[i].s.f >> a[i].s.s;
    }
    sort(a.begin(),a.end());
    if(cur < a[0].s.f){
        cout << "NO\n";
        return
    }
    for(int i=0;i<n-1;++i){
        if((a[i+1].f - a[i].f) < (a[i+1].s.f - a[i].s.f)){

        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
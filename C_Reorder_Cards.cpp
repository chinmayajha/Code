
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
bool srt(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    return (a.first.second < b.first.second);
}
bool srt2(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    return (a.second < b.second);
}
void solve(){
    i64 h,w,n,a,b;cin >> h >> w >> n;
        
    vector<vector<int>>v(n,vector<int>());

    for(int i = 0; i < n; i++){
        cin>>a>>b;
        vector<int> y(5);
        y[0] = a,y[1] = b,y[2] = i+1,y[3] = -1,y[4] = -1;
        v[i] = y;
    }
    
    sort(all(v),[&](vector<int> &v1,vector<int> &v2){return v1[0]<v2[0];});
    
    int cnt=1;
    for(int i=0;i<n;i++){
        if(i && v[i-1][0]!=v[i][0]) cnt++;
        v[i][3] = cnt;
    }

    sort(all(v),[&](vector<int> &v1,vector<int> &v2){return v1[1]<v2[1];});
    
    cnt=1;
    for(int i=0;i<n;i++){
        if(i && v[i-1][1]!=v[i][1]) cnt++;
        v[i][4] = cnt;
    }

    sort(all(v),[&](vector<int> &v1,vector<int> &v2){return v1[2]<v2[2];});
    
    for(int i=0;i<n;i++) cout<<v[i][3]<<" "<<v[i][4]<<"\n";
    
    
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



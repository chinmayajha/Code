
#include "bits/stdc++.h"
using i64 = long long int;
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
string solve(){
    int n,m; 
    cin >> n >> m;
    vector<string> a(n);
    inarr(a,n);
    vector<vector<bool>> ought(n, vector<bool>(m, 0));
    for(int i = 1; i < n - 1; ++i)for(int j = 1; j < m - 1; ++j){
        if (!(a[i][j] == '*' && a[i][j-1] == '*' && a[i][j+1] == '*' && a[i-1][j] == '*' && a[i+1][j] == '*'))continue;
        int top = i, bottom = i;
        int left = j, right = j;
        while(left >= 0 && a[i][left] == '*') {ought[i][left] = 1; left--;}
        while(top >= 0 && a[top][j] == '*') {ought[top][j] = 1; top--;}
        while(right < m && a[i][right] == '*') {ought[i][right] = 1; right++;}
        while(bottom < n && a[bottom][j] == '*') {ought[bottom][j] = 1; bottom++;}

            //CHECKING
        for(int k = 0; k < n; ++k)for(int l = 0; l < m; ++l){
            if(ought[k][l] - (a[k][l] == '*') != 0)return "NO";
        }
        return "YES";
    }
    return "NO";
    
    
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        cout << solve();
    }
}
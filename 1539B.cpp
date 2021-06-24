#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    int n;cin>>n;
    int q;cin>>q;
    string s;cin>>s;
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i=1;i<n+1;++i){
        dp[i] = dp[i-1] +  (s[i-1] - 'a' + 1);
    }
    // for(int i=0;i<n+1;++i){
    //     cout << dp[i] << " ";
    // }
    for(int i=0;i<q;++i){
        int x,y;cin >> x >> y;
        cout << dp[y] - dp[x-1] << "\n";
    }
}
int main(){
    solve();
}
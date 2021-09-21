
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
#ifndef ONLINE_JUDGE
    #include "debug.hpp"
#else
    #define print(...)
    #define debug(...)
#endif
long int SubArraySum( int arr[] , int n )
{
    long int result = 0;
 
    // computing sum of subarray using formula
    for (int i=0; i<n; i++)
        result += (arr[i] * (i+1) * (n-i));
 
    // return all subarray sum
    return result ;
}
void solve(){
	int n; cin >> n;
    string s; cin >> s;
    int dp[n]; //s[i] at dp[i + 1]
    dp[0] = 0;
    bool changed = (s[0] == 'O');
    int i = 1;
    while(i < n) {
        if(s[i] == 'F') {
            dp[i] = dp[i - 1];
        } else if(s[i] == 'X') {
            if(changed) {
                dp[i] = dp[i - 1] + 1;
                changed = 0;
            } else {
                dp[i] = dp[i - 1];
            }
        } else {
            if(changed) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = dp[i - 1] + 1;
                changed = 1;
            }
        }
        i++;
    }
    for(auto& k : dp) {cerr << k << " ";} cerr << "\n";
    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}

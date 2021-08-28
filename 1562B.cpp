
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
bool isprime(int n){
    if (n <= 1)
        return 1;
    for (int i = 2; i*i <= n; i++) if (n % i == 0) return 1;
    return 0;
}
void solve(){
    int k; cin >> k;
    string s; cin >> s;
    map<int,int> a;
    for(auto& i : s) {
        int z = (i - '0');
        if(z != 2 && z % 2 == 0) {
            cout << "1\n" << i << "\n";
            return;
        } else if(i == '9' || i == '1') {
            cout << "1\n" << i << "\n";
            return;
        }
        a[z]++;
    }
    for(auto& i : s) {
        if(a[i - '0'] >= 2) {
            cout << "2\n" << i << i << "\n";
            return;
        }
        
    }
    
    for(int i = 0; i < k; ++i) for(int j = i + 1; j < k; ++j) {
        if(isprime((s[i] - '0')*10 + (s[j] - '0'))) {
            cout << "2\n" << (s[i] - '0')*10 + (s[j] - '0') << "\n";
            return;
        }
    }

    

}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}



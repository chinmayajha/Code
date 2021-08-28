
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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    inarr(a, n);
    b = a;
    sort(all(b));
    int i = 1;
    while(!equal(all(a), b.begin())) {
        if(i%2){
            for(int j = 0; j < n; j+=2){
                if(j+1 < n && a[j] > a[j+1]) swap(a[j], a[j+1]);
            }
        } else {
            for(int j = 1; j < n; j+=2){

                if(j+1 < n && a[j] > a[j+1]) swap(a[j], a[j+1]);
            }
        }
        i++;
    }
    cout << i - 1 << "\n";
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



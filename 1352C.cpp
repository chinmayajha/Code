#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;
lli n,k;
lli chk(lli x){
    return x - (x/n);
}
void solve(){
    cin>>n>>k;
    if(k < n){
        cout << k;
    } else if (n==k) {
        cout << n+1;
    } else {
        lli l = 0;
        lli r = 1e18;
        while(r>=l){
            lli mid = l + (r-l)/2;
            lli z = chk(mid);
            if(z >= k){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        cout << l;
    }
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
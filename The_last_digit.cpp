
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
int binpow(int x, i64 y){return (int)pow(x, y);}

void solve(){
    i64 a,b; cin >> a >> b;
    a%=10;
    if(a==0){cout<<"0\n";return;}
    else if(b==0){cout<<"1\n";return;}
    else if(a==1){cout<<"1\n";return;}
    b %= 4;
    if(b!=0)cout<<binpow(a%10,b)%10;
    cout << "\n";

}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
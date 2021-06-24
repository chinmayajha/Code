/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-06-21 21:16:16
*/

#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    int a,b;cin >> a >> b;
    if(a<b)swap(a,b);
    if(!a)cout << "0";
    else if(!b)cout << "0";
    else {
        if(a >= 2*b){
            cout << b;
        } else {
            cout << (a+b)/3;
        }
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
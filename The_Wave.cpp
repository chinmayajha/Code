#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;
/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-06-21 09:12:47
*/

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    for(int i=0;i<q;++i){
        int e;
        cin >> e;
        int cur = 1;
        for(auto rr : a){
            if(e - rr == 0){
                cur = 0;
                break;
            }
            cur *= (e - rr)/abs(e - rr);
        }
        if(cur == 0){
            cout << "0\n";
        } else if(cur > 0){
            cout << "POSITIVE\n";
        } else cout << "NEGATIVE\n";
    }
    
}
int main(){
    solve();
}
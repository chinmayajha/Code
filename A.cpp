#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    vector<int> a{1,1,1,1,1,1,1,2,3,4,4,4,4,4,8};
    cout << upper_bound(a.begin(),a.end(), 1) - a.begin();
}
int main(){
    solve();
}
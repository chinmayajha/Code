/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-09-14 03:26:08
*/

#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
int main(){
    i64 n; cin >> n;
    vector<i64> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    i64 sum = 0;
    for(i64 i = 0; i < n; ++i) {
        sum += (i*a[i] - (n - i - 1)*a[i]);
    }
    cout << sum;
}

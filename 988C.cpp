
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif


void solve(){
    int64_t n; cin >> n;
    vector<pair<int64_t, pair<int64_t, int64_t>>> a;

    //store elements of all seqeunces together in 1 array, in the form of 
    // {sum of sequence without them, index of their seqeunce, index of them in their sequence}
    // sorting the elements gives us a clear view over the places where adjacent sums are equal (as we've already calculates sums excluding that element)
    // (our work has been done.) now we just need to identify DIFFERENT seqeunces with same sums, and output their I and J respectively

    for(int64_t i = 0; i < n; ++i) {
        int64_t ni; cin >> ni;
        vector<int64_t> b(ni);
        for(int64_t j = 0; j < ni; ++j) cin >> b[j];
        int64_t sum = accumulate(all(b), 0);
        
        for(int64_t j = 0; j < ni; ++j) {
            a.push_back(make_pair(sum - b[j], make_pair(i + 1, j + 1)));
        }
    }
    sort(all(a));

    for(int64_t i = 1; i < sz(a); ++i) {
        if((a[i].first == a[i - 1].first) && (a[i].second.first != a[i - 1].second.first)) {
            cout << "YES\n";
            cout << a[i].second.first << " " << a[i].second.second << "\n";
            cout << a[i - 1].second.first << " " << a[i - 1].second.second << "\n";
            return;
        } 
    }
    
    cout << "NO\n";
    
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

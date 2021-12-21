// # FOR SUBTASK 3 ONLY
#include "bits/stdc++.h"
using namespace std;

int n, q, l, r, i;
pair<pair<int, int>, int> a[int(3e5 + 10)];
// vector<int> b(int(3e5 + 10), 2);
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> q;
    vector<int> b(n);
    for(int j = 0; j < n; ++j) b[j] = j + 1;

    int check = 1;
   for(int j = 0; j < q; ++j) {
        cin >> l >> r >> i; l--; r--; i--;
        a[j].first.first = l;
        a[j].first.second = r;
        a[j].second = i;
    }
    
    while(check) {
        for(int j = 0; j < q; ++j) {
            l = a[j].first.first;
            r = a[j].first.second;
            i = a[j].second;
            if(*min_element(b.begin() + l, b.begin() + r + 1) != b[i]) {
                next_permutation(b.begin(), b.end());
                break;
            }
            check = 0;
        }
    }
    for(i = 0; i < n; ++i) cout << b[i] << " ";
}

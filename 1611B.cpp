
#include "bits/stdc++.h"
using namespace std;
int t, n, m;
int main(){
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << min((n + m) / 4, min(n, m)) << "\n";
    }
}

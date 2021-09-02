
#include <bits/stdc++.h>
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];

//
int getor(int i, int j) {
    int x;
    cout << "or " << i << " " << j << endl;
    cin >> x;
    return x;
}
int getand(int i, int j) {
    int x;
    cout << "and " << i << " " << j << endl;
    cin >> x;
    return x;
}
int arr[200010];
void solve(){
    int n, k;
    cin >> n >> k;
    int a, b, c;
    a = getor(1, 2) + getand(1, 2);
    b = getor(2, 3) + getand(2, 3);
    c = getor(1, 3) + getand(1, 3);

    arr[1] = (a - b) + c;
    arr[1] /= 2;
    arr[2] = a - arr[1];
    arr[3] = b - arr[2];
    for(int j = 4; j < n + 1; ++j) {
        arr[j] = getor(j - 1, j) + getand(j - 1, j) - arr[j - 1];
    }
    sort(arr+1, arr+n+1);
    cout << "finish " << arr[k] << endl;
    exit(0);
}

int main(){
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

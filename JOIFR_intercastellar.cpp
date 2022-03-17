// https://cms.ioi-jp.org/tasks/2022-ho-t1/submissions?submission_id=npfTM5qV3K13lUa7GhZO3C4b4CCx20snIylFJNdvEsc.
#include "bits/stdc++.h"
using namespace std;
#define int long long

int binpow(int a, int b) {
    int res = 1; while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a; b >>= 1;
    }
    return res;
}

int gettwos(int n) {
    int cnt = 0;
    while(n % 2 == 0) cnt += 1, n /= 2;
    return cnt;
}

int n, qq, x, temp;
vector<pair<int, int>> a;

signed main() {
    cin >> n;
    while(n--) {
        cin >> x; temp = binpow(2, gettwos(x));
        a.push_back({temp, x / temp});
    }
    for(int i = 1; i < (int) a.size(); ++i) a[i].first += a[i - 1].first;
    cin >> qq;
    while(qq--) {
        cin >> x;
        auto ind = distance(a.begin(), lower_bound(a.begin(),a.end(), make_pair(x, numeric_limits<int>::min())) );
        cout << a[ind].second << "\n";
    }
}
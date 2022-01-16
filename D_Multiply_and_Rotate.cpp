#include "bits/stdc++.h"
using namespace std;
#define int long long

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int diglen(int x) {
    int ans = 0;
    while(x > 0) ans++, x /= 10;
    return ans;
}

int converted(int num) {
    int dig = diglen(num);
    int last = num % 10;
    num /= 10;
    num += last * (int) binpow(10, dig - 1);
    return num;
}

int a, n;

signed main() {
    cin >> a >> n;
    deque<pair<int, int>> q;
    vector<int> vis(1000000, 0);
    q.push_back(make_pair(1, 0));
    while(!q.empty()) {
        auto cur = q.front();
        q.pop_front();
        if(cur.first == n) {
            cout << cur.second;
            return 0;
        }
        if(cur.first * a <= 1000000 && vis[cur.first * a] == 0) {
            vis[cur.first * a] = 1;
            q.push_back(make_pair(cur.first * a, cur.second + 1));
        }
        if(cur.first <= 9 || cur.first % 10 == 0) continue;
        cur.first = converted(cur.first);
        if(cur.first <= 1000000 && vis[cur.first] == 0){
            vis[cur.first] = 1;
            q.push_back(make_pair(cur.first, cur.second + 1));
        }
    }
    cout << "-1";
}

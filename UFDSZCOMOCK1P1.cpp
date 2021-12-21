
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

int64_t a, b, k, l, ans, current_steps;
set<pair<int64_t, int64_t>> s;
map<pair<int, int> , int> ss;
void solve(){
    queue<pair<int64_t, int64_t>> q;
    q.push({0, 0});
    q.push({-1, -1}); // to check ending of a particular K

    while(sz(q) > 1) {
        pair<int64_t, int64_t> cur = q.front(); q.pop();
        if(current_steps > k) return;
        if(cur == make_pair(-1ll, -1ll)) {
            current_steps += 1;
            q.push({-1, -1}); //particular K ended
            continue;
        }

        ans = min(abs(l - (cur.first + cur.second)), ans);

        pair<int64_t, int64_t> cur1 = cur, cur2 = cur, cur3 = cur, cur4 = cur, cur5 = cur, cur6 = cur;
    //
        cur1.first = a;
        cur2.second = b;
        cur3.first = min(a, cur.first + cur.second), cur3.second = max(0ll, cur.second - cur3.first + cur.first);
        cur4.second = min(b, cur.first + cur.second), cur4.first = max(0ll, cur.first - cur4.second + cur.second);
        cur5.first = 0;
        cur6.second = 0;

        // if(!binary_search(all(s), cur1)) {
        //     s.insert(cur1);
        //     q.push(cur1);
        // }
        // if(!binary_search(all(s), cur2)) {
        //     s.insert(cur2);
        //     q.push(cur2);
        // }
        // if(!binary_search(all(s), cur3)) {
        //     s.insert(cur3);
        //     q.push(cur3);
        // }
        // if(!binary_search(all(s), cur4)) {
        //     s.insert(cur4);
        //     q.push(cur4);
        // }
        // if(!binary_search(all(s), cur5)) {
        //     s.insert(cur5);
        //     q.push(cur5);
        // }
        // if(!binary_search(all(s), cur6)) {
        //     s.insert(cur6);
        //     q.push(cur6);
        // }
        if(!ss[cur1]) {
            ss[cur1] = 1;
            q.push(cur1);
        }
        if(!ss[cur2]) {
            ss[cur2] = 1;
            q.push(cur2);
        }
        if(!ss[cur3]) {
            ss[cur3] = 1;
            q.push(cur3);
        }
        if(!ss[cur4]) {
            ss[cur4] = 1;
            q.push(cur4);
        }
        if(!ss[cur5]) {
            ss[cur5] = 1;
            q.push(cur5);
        }
        if(!ss[cur6]) {
            ss[cur6] = 1;
            q.push(cur6);
        }

    }

}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> a >> b >> k >> l;
    ans = l;
    solve();
    cout << ans;
}

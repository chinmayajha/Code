// https://codeforces.com/group/fXPc2tNEPp/contest/362551/problem/B
#include "bits/stdc++.h"
using namespace std;
#define int long long

struct element {
    int x, y, m, e;
};
bool cmp(element& p, element& q) {
    return p.y > q.y;
}

int n, h;
vector<element> a;

void preprocess() {
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y >> a[i].m >> a[i].e;
    if(all_of(a.begin(), a.end(), [](element p){return (p.e == (int) 2e5);})) {
        // subtask 1 DONE
        int sum = 0;
        for(auto& i : a) sum += i.m;
        cout << sum;
        exit(0);
    }
    if(all_of(a.begin(), a.end(), [](element p){return (p.x == 0);})) {
        // subtask 2
        int sum = 0;
        for(auto& i : a) sum += i.m;
        cout << sum;
        exit(0);
    }

}

signed main() {
    cin >> n >> h;
    preprocess();
}
#include "bits/stdc++.h"
using namespace std;
#define int long long

struct barn {
    int x, y, v;
};
struct barn2 {
    int dist, v;
};
vector<barn> a;
vector<barn2> b;
int n, v_ans = 0, v_dist = 0, cur_dist = 0, cur = 0;

void preprocess() {
    bool check = 1; for(auto& i : a) check = min(check, (i.v <= 0));
    bool check2 = 1; for(auto& i : a) check2 = min(check2, (i.v >= 0));
    bool check3 = 1; for(auto& i : a) check3 = min(check3, i.x == i.y);
    if(n == 1 || check || check2 || check3) {
        // subtask 1 3 5 DONE
        sort(a.begin(), a.end(), [](barn& p, barn& q){return p.x < q.x;});
        int ind = 0; 
        for(int i = 0; i < n; ++i) {
            if(a[i].x >= 0) {
                ind = i;
                break;
            }
        }
        vector<int> w1, w2;
        w1.push_back(0); w2.push_back(0);
        for(int i = ind; i < n; ++i) {
            w1.push_back(w1.back() + a[i].v);
        }
        for(int i = ind - 1; i >= 0; --i) {
            w2.push_back(w2.back() + a[i].v);
        }
        cout << *max_element(w1.begin(), w1.end()) + *max_element(w2.begin(), w2.end());
        exit(0);
    }
}

signed main() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].v;
    }
    preprocess();
}
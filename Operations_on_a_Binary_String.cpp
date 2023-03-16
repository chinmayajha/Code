#include "bits/stdc++.h"
using namespace std;

vector<int> split(string s, char c) {
    vector<int> a;
    string t = "";
    for(int i = 0; i < (int) s.size(); ++i) {
        if(s[i] == c) {
            if(t.size() > 0) a.emplace_back(2 * t.size() + 1);
            t = "";
        } else t.push_back(s[i]);
    }
    if(t.size() > 0) a.emplace_back(2 * t.size() + 1);
    sort(a.rbegin(), a.rend());
    return a;
}

int main() {
    int t = 1; cin >> t;
    while (t--) {
        int n, c, freq1 = 0; cin >> n >> c;
        string s; cin >> s;
        for(auto& i : s) freq1 += (i == '1');

        vector<int> cost = split(s, '1');
        for(auto& i : cost) {
            if(c <= 0) break;
            freq1 += (min(c, i) - 1) / 2;
            c -= i;
        }
        cout << freq1 << "\n";
    }
}

#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())

int toint(const string& s) {stringstream ss;ss << s;int x;ss >> x;return x;}
string tostring(int number) {stringstream ss; ss << number;return ss.str();}
int main(){
    vector<vector<int>> a(9, vector<int>(9, 0));
    string s; cin >> s;
    int n = sz(s);
    int mx = 0;
    for(int i = 0; i < n; ++i) {
        int dig = s[i] - '0';
        mx = max(mx, dig);
        for(int j = 0; j < dig; ++j) {
            a[i][j] = 1;
        }
    }
    vector<int> ans;
    for(int j = 0; j < mx; ++j) {
        string ans2;
        for(int i = 0; i < n; ++i) ans2.push_back(tostring(a[i][j])[0]);
        ans.push_back(toint(ans2));
    }
    cout << sz(ans) << "\n";
    for(auto& i : ans) cout << i << " ";
}

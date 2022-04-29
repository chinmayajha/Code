#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    if(s[0] != '1' || s.back() != '0') return 0;
    for(int i = 0; i < (int) s.size() - 3; ++i) {
        if(s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '1') return 0;
    }
    return 1;
}

int main() {
    string str;
    int ans = 0;
    for(int i = 1; i < (1 << 11); ++i) {
        str = std::bitset<10>(i).to_string();
        if(check(str)) {
            ans += 1;
            cerr << str << endl;
        }
    }
    cout << ans;
}

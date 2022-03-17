#include "bits/stdc++.h"
using namespace std;

bool is_palindrome(string s) {
    int x = (int) s.size();
    for(int i = 0; i< x; ++i) if(s[i] != s[x - i - 1]) return 0;
    return 1;
}

signed main() {
    string s; cin >> s;
    int x = 0, y = 0;
    for(auto& i : s) {
        if(i != 'a') break;
        x++;
    }
    reverse(s.begin(), s.end());
    for(auto& i : s) {
        if(i != 'a') break;
        y++;
    }
    if(x > y) {
        cout << "No";
        exit(0);
    }
    if(is_palindrome(s.substr(y, - x - y + (int) s.size()))) cout << "Yes";
    else cout << "No";
}

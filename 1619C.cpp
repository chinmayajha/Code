
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long

#ifdef chinmayajha
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif

string tostring(int number) {stringstream ss; ss << number;return ss.str();}
int toint(const string& s) {stringstream ss;ss << s;int x;ss >> x;return x;}

int countDigit(int n)
{
    int count = 0;
    while (n != 0){
        n = n / 10;
        ++count;
    }
    return count;
}
string solve() {
    int a, s; cin >> a >> s;
    if(countDigit(s) < countDigit(a)) return "-1";
    string b;
    while(1) {
        if(a % 10 > s % 10) {
            int dig = (s % 100) - (a % 10);
            a /= 10;
            s /= 100;
            if(dig < 0 || dig > 9) return "-1";
            string to_add = tostring(dig);
            reverse(all(to_add));
            b += to_add;
        } else {
            int dig = (s % 10) - (a % 10);
            a /= 10;
            s /= 10;
            if(dig < 0 || dig > 9) return "-1";
            string to_add = tostring(dig);
            reverse(all(to_add));
            b += to_add;
        }
        if(countDigit(s) < countDigit(a)) return "-1";
        if(s == 0) {
            reverse(all(b));
            int x = toint(b);
            b = tostring(x);
            return b;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i) {
        // cout << "Case #" << i << ": ";
        cout << solve() << "\n";
    }
}

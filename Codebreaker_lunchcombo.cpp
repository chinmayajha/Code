
// https://codeforces.com/group/fXPc2tNEPp/contest/362551/problem/A
#include "bits/stdc++.h"
using namespace std;
#define int long long

int g, a, n;
vector<int> gun, armor;

/*
Subtask 3 [12 points]: G,A≤3000
Subtask 5 [24 points]: N≤3×105 and all gun prices and all armour prices are at most 100
Subtask 7 [14 points]: N≤3×105
Subtask 8 [16 points]: No additional constraints. 
*/
vector<int> m((int) 2e6 + 10, 0);
void preprocess() {
    gun.resize(g);
    armor.resize(a);
    for(int i = 0; i < g; ++i) cin >> gun[i];
    for(int i = 0; i < a; ++i) cin >> armor[i];
    if(n == 1) {
        // subtask 2  DONE
        cout << *min_element(armor.begin(), armor.end()) + *min_element(gun.begin(), gun.end());
        exit(0);
    }
    if(n == g * a) {
        // subtask 6  DONE
        int temp = g * accumulate(armor.begin(), armor.end(), 0ll);
        temp += a * accumulate(gun.begin(), gun.end(), 0ll);
        cout << temp;
        exit(0);
    }
    bool check1 = all_of(gun.begin(), gun.end(), [](int i){ return i == 1; });
    bool check2 = all_of(armor. begin(), armor.end(), [](int i){ return i == 1; });
    if(check1 && check2) {
        // subtask 1  DONE
        cout << 2 * n;
        exit(0);
    }
    if(check1) {
        // subtask 4  DONE
        sort(armor.begin(), armor.end());
        int i = 0, sum = 0;
        while(n - g > 0) {
            sum += (g * (armor[i] + 1));
            n -= g;
            i++;
        }
        sum += (n * (armor[i] + 1));
        cout << sum;
        exit(0);
    }
    // now last hope, put every possible sum in a multiset and print final answer
    // This doesnt work, :sob:
    if(g <= 3000 && a <= 3000) {
        vector<int> mp;
        for(auto& i : armor) for(auto& j : gun) {
            if(m[i + j] == 0) mp.push_back(i + j);
            m[i + j]++;
        }
        sort(mp.begin(), mp.end());
        int ans = 0;
        for(auto& i : mp) {
            if(m[i] == 0) continue;
            if(m[i] <= n) {
                ans += (i * m[i]);
                n -= m[i];
                continue;
            }
            ans += (i * n);
            break;
        }
        cout << ans;
        exit(0);
    }
}

signed main() {
    cin >> g >> a >> n;
    preprocess();
}
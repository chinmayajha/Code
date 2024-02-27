#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        char tr; cin >> tr;

        vector<char> trump;
        map<char, priority_queue<char, vector<char>, greater<char>>> mp;
        for(int i = 0; i < 2 * n; ++i) {
            string s; cin >> s;
            if(s[1] == tr) trump.push_back(s[0]);
            else mp[s[1]].push(s[0]);
        }
        sort(trump.begin(), trump.end());

        vector<string> ans, leftover;
        string x, y;

        for(auto& i : mp) {
            while (i.second.size() >= 2) {
                x = i.second.top(); i.second.pop();
                y = i.second.top(); i.second.pop();

                ans.push_back(x + i.first);
                ans.push_back(y + i.first);
            }

            while(!i.second.empty()) {
                char j = i.second.top(); i.second.pop();
                string s = ""; s.push_back(j); s.push_back(i.first);
                leftover.push_back(s);
            }
        }

        if(leftover.size() > trump.size() || (trump.size() - leftover.size()) % 2 == 1) {
            cout << "IMPOSSIBLE\n";
        } else {
            for(int i = 0; i < leftover.size(); ++i) {
                ans.push_back(leftover[i]);
                string s = ""; s.push_back(trump[i]); s.push_back(tr); 
                ans.push_back(s);
            }

            for(int i = leftover.size(); i < (int) trump.size() - 1; i += 2) {
                string s = ""; s.push_back(trump[i]); s.push_back(tr); 
                ans.push_back(s);
                s = ""; s.push_back(trump[i + 1]); s.push_back(tr); 
                ans.push_back(s);
            }

            bool check = 1;
            for(auto& i : ans) {
                cout << i << (check ? " " : "\n");
                check = 1 - check;
            }
        }
    }
}

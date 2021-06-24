#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;

bool check(string s){
    for(int i=0;i<int(s.size());++i){
        if(s[i]!=s[int(s.size())-i-1]){
            return 0;
        }
    }
    return 1;
}
string s;
void solve(){
    // cerr << check("abab");
    int n,m; cin >> n >> m;
    vector<string> a(n);
    for(int i=0;i<n;++i)cin >> a[i];
    vector<string> p;
    vector<string> q;
    string temp = "";
    for(int i=0;i<n;++i){
        string cur = a[i];
        reverse(cur.begin(),cur.end());
        if(cur == a[i])temp = cur;
        else {
            for(int j=0;j<n;++j)
                if(a[j] == cur){
                    p.emplace_back(a[i]);
                    q.emplace_back(cur);
                    a[j] = "+-_=";
                    a[i] = "&$&(";
                    break;
                }
        }
    }
    reverse(q.begin(),q.end());
    cout << (int(q.size())+int(q.size()))*m +int(temp.size()) << "\n";
    for(auto& i : p)cout << i;
    cout << temp;

    for(auto& i : q)cout << i;
    cout << "\n";
}
int main(){
    solve();
}
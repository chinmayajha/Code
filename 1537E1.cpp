#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    int n,m;cin>>n;
    string s;
    cin >> s;
    string a = "";
    string b = "";
    while(a.size() < m && b.size() - n < m){
        a.append(s);
        b.append(s);
    }
    a = a.substr(0,m);
    while(b.size())

}
int main(){
    solve();
}
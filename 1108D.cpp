/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-06-22 23:42:10
*/

#include "bits/stdc++.h"
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<n;++i){
        int j = i;
        while(j<n && s[i]==s[j])j++;
        string temp = "RGB";
        temp.erase(temp.find(s[i]),1);
        if(j<n)temp.erase(temp.find(s[j]),1);
        for(int k=i+1;k<j;k+=2){
            cnt++;
            s[k] = temp[0];
        }
        i = j-1;
    }
    cout << cnt << endl << s;
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
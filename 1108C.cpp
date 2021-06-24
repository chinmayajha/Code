

#include "bits/stdc++.h"
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    int n; cin >> n;
    string a1="",a2="",a3="",a4="",a5="",a6="";
    string s;cin >> s;
    vector<string> arr1{"B","G","R"};
    vector<string> arr2{"B","R","G"};
    vector<string> arr3{"G","R","B"};
    vector<string> arr4{"G","B","R"};
    vector<string> arr5{"R","G","B"};
    vector<string> arr6{"R","B","G"};

    for(int i=0;i<n;++i){
        a1.append(arr1[i%3]);
        a2.append(arr2[i%3]);
        a3.append(arr3[i%3]);
        a4.append(arr4[i%3]);
        a5.append(arr5[i%3]);
        a6.append(arr6[i%3]);
    }
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0;
    for(int i=0;i<n;++i){
        cnt1 += (s[i]!=a1[i]);
        cnt2 += (s[i]!=a2[i]);
        cnt3 += (s[i]!=a3[i]);
        cnt4 += (s[i]!=a4[i]);
        cnt5 += (s[i]!=a5[i]);
        cnt6 += (s[i]!=a6[i]);
    }
    vector<pair<int,string>> w{{cnt1,a1},{cnt2,a2},{cnt3,a3},{cnt4,a4},{cnt5,a5},{cnt6,a6}};
    sort(w.begin(),w.end());
    cout << w[0].first << "\n" << w[0].second; 
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
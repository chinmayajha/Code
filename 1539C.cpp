#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    lli n,k,x;cin >> n >> k >> x;
    vector<lli> a(n),b;
    for(lli i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.end());
    for(lli i=1;i<n;++i){
        if(abs(a[i]-a[i-1]) > x){
            b.emplace_back(abs(a[i] - a[i-1]));
        }
    }
    sort(b.begin(),b.end());
    lli cnt = b.size()+1;
    /////////////
    for(auto& i : b){
        lli m = i/x - (i%x==0?1:0);
        if(k>=m){
            k -= m;
            cnt--;
        } else break;
    }
    cout << max(cnt,0ll) << "\n";
}
int main(){
    solve();
}
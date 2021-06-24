/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-06-21 22:29:40
*/


#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;
template< class T >
void printa(T begin, T end){
	T it = begin;
	while(it < end)
		cout << *it++ << " ";
	cout << "\n";
}
void solve(){
    int n,k;cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;++i)cin >> a[i];
    
    if(*max_element(a.begin(),a.end()) * n < k) cout << "-1\n";
    else {
        int cnt = 0;
        for(int j=0;j<k;++j){
            int ind = -2;
            for(int i=0;i<n-1;++i){
                if(a[i+1]>a[i]){
                    ind = i;
                    break;
                }
            }
            cnt = ind+1;
            if(ind != -2){
                a[ind]++;
            } else break;
        }
        cout << cnt << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
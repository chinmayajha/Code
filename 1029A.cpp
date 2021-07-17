
    #include "bits/stdc++.h"
    using i64 = long long int;
    using namespace std;
    #define sz(x) ((int)(x).size())
    #define all(x) (x).begin(), (x).end()
    #define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
    #ifndef ONLINE_JUDGE
        #define db(x) cerr << #x <<" = " << x << "\n";
    #else
        #define db(...)
    #endif
    //
    void solve(){
        int n,k;cin >> n >> k;
        k--; string s; cin >> s;
        string start = "";
        for(int i=1;i<n;++i){
            string a,b;
            a = s.substr(0,i);
            b = s.substr(n-i,i);
            if(a != b)break;
            start = a;
        }
        string last = s.substr(sz(start),n - sz(start));
        cout << s;
        while(k--) cout << last;
    }

    int main(){
        cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
        int testt = 1;
        // cin >> testt;
        for (int i = 0; i < testt; ++i) {
            // cout << "Case #" << i << ": ";
            solve();
        }
    }

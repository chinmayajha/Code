#include<bits/stdc++.h>
using namespace std;
#define nline "\n"
#define mod 1000000007
#define mod1 998244353
typedef long long ll;

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int steps(int n)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; ++i)
    {
        int a = i % 10;
        i = i / 10;

        dp[i] = INT_MAX;
        dp[i] = min(dp[i], 1 + dp[i - a]);
    }
    return dp[n];

}



int main() {

    fastIO

    int n; cin >> n;
    cout << steps(n) << nline;

    return 0;
}
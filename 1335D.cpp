
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    /*
        Main idea for this problem is to break all the sudoku rules in 1 game itself
        The simplest way we can achieve this is -
        We know that we need to have a common number in each row, each column, and in each 9x9 box.
        Now if you look at ANY complete sudoku puzzle, you'll notice that every number occurs in every row, column and 9x9 grid (obviously).
        So if we replace a number, say 6 with a 9, then we'll have two nines in every row, column and 9x9 grid
        (one original, and one in the place of 6)
    */
    vector<string> a(9);
    inarr(a,9);
    //So the problem simply boils down to replacing every 6 with a 8 :feelscoffeeman:
    for(auto& i : a) for(auto& j : i) if(j == '6') j = '9';
    for(auto& i : a) {cout << i << "\n";}
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}



/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-08-09 20:14:16
*/
#include "bits/stdc++.h"
using namespace std;
int main(){
    long long int n,m; cin >> n >> m;
    vector<long long int> a(m);
    for(auto& i : a) {
        cin >> i; //taking input
        if(i == 1 || i == n) {
            cout << "NO";
            exit(0);
        }
        /*
            We need to check that if the first step or the last step are dirty or not.
            If they're dirty then no matter what you do, you cannot escape them.
            Therefore we print NO and exit immediately
        */
    }
    sort(a.begin(),a.end());
    /*
        Now the problem states that, you can move to the next step, the next to next step, or the next to next to next step.
        So the only place where you cannot avoid a dirty step is when there are 3 consecutive dirty steps in a row
        For example ...XX.......XXX....X....
        X is a dirty step, you can easily skip the X and XX parts, but you cannot skip the XXX part no matter what you do.
        So we just write a for loop to check that if there are 3 consecutive dirty steps in a row (after sorting)
    */ 
    for(long long int i=0;i<m-2;++i){
        if(a[i] == a[i+1]-1 && a[i+1] == a[i+2]-1) {
            cout << "NO";
            exit(0);
        }
    }
    cout << "YES";
}



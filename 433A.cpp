
#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, a = 0, b = 0; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x == 100) a++;
        else b++;
    }
    int value_100 = 100*a, value_200 = 200*b;
    if((value_200 + value_100) % 200 != 0) cout << "NO";
    else {
        bool check = 0;
        int half = (value_200 + value_100) / 2;
        for(int i = 0; i <= b; ++i) {
            if(200 * i <= half && half - 200 * i <= value_100) check = 1;
        }
        cout << (check ? "YES" : "NO");
    }

}
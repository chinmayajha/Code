#include "bits/stdc++.h"
using namespace std;
#define int long long

bool isPrime(int num){
    if(num <= 1) return false;
    for(int i = 2; i * i <= num; i++){
          if(num % i == 0) return false;
    }
    return true;
}

signed main() {
    int n; cin >> n;
    if(isPrime(n)) cout << "YES";
    else cout << "NO";
}

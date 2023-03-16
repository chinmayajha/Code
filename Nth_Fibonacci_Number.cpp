#include "bits/stdc++.h"
using namespace std;

int main() {
    vector<long long> a(10000, 0);
    a[1] = 1;
    for(int i = 2; i < 10000; i++) a[i] = a[i - 1] + a[i - 2];
    long long n; cin >> n; 
    cout << a[n];
}
// 
#include <bits/stdc++.h>
class NthFibonacciNumber
{
    public:
        int getFibonacciNumber(int n) {
            int a[n + 1] = {0};
            a[1] = 1;
            for(int i = 2; i < n + 1; i++) a[i] = a[i - 1] + a[i - 2];
            return a[n];
        }
};

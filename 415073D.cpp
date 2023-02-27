#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int x1, x2, x3, y1, y2, y3, a, b, c;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    a = (x1 * (y3 - y2) + x2 * (y1 - y3) + x3 * (y2 - y1)) / ((x1 - x2) * (x1 - x3) * (x2 - x3));
    b = (y2 - y1) / (x2 - x1) - a * (x1 + x2);
    c = y1 - a * x1 *  x1 - b * x1;

    cout << a + b + c;
}

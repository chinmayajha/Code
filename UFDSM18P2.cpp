#include "bits/stdc++.h"
using namespace std;

vector<pair<pair<int, int>, int>> a;
int n, temp1 = 0, temp2 = 0, temp3 = 0;

signed main() {
    cin >> n;
    a.resize(n);
    vector<int> ans(n), ans2(n), ans3(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {return x.first.first < y.first.first;});
    for(int i = 1; i < n; ++i) {
        temp1 += (abs(a[i].first.first - a[i - 1].first.first) + abs(a[i].first.second - a[i - 1].first.second));
    }
    for(int i = 0; i < n; ++i) ans[a[i].second] = i + 1;
    sort(a.begin(), a.end(), [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {return x.first.first < y.first.first;});
    for(int i = 1; i < n; ++i) {
        temp2 += (abs(a[i].first.first - a[i - 1].first.first) + abs(a[i].first.second - a[i - 1].first.second));
    }
    for(int i = 0; i < n; ++i) ans2[a[i].second] = i + 1;   
    sort(a.begin(), a.end(), [](pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {return x.first.first + x.first.second < y.first.first + y.first.second;});   
    for(int i = 1; i < n; ++i) {
        temp3 += (abs(a[i].first.first - a[i - 1].first.first) + abs(a[i].first.second - a[i - 1].first.second));
    }
    for(int i = 0; i < n; ++i) ans3[a[i].second] = i + 1;
    

    if(temp1 == min({temp1, temp2, temp3})) for(auto& i : ans) {cout << i << " ";} 
    else if(temp2 == min({temp1, temp2, temp3})) for(auto& i : ans2) {cout << i << " ";} 
    else if(temp3 == min({temp1, temp2, temp3})) for(auto& i : ans3) {cout << i << " ";} 
}
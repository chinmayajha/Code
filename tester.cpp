#include <bits/stdc++.h>
using namespace std;
#define int long long
int ceildiv(int x, int y) {
	return (x + y - 1) / y;
}

signed main() {
	vector<pair<int, int>> a;
	a.push_back({1, 2});
	a.push_back({1, 1});
	a.push_back({1, -1});
	a.push_back({1, -2});

	sort(a.begin(), a.begin() + 2, [](pair<int, int> xx, pair<int, int> yy){ return xx.second < yy.second;});
	for(auto& i : a) {cout << i.first << " " << i.second << "\n";} cout << "\n";
}

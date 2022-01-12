
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long

#include <random>
int gener(int l = 0, int r = INT_MAX - 100) {
	// source : https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(l, r);
	return distrib(gen);
}
vector<int> gener2(int n, int l = 0, int r = INT_MAX - 100) {
	// source : https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> distrib(l, r);
	vector<int> a;
	for (int i = 0; i < n; ++i) { a.push_back(distrib(gen)); }
	return a;
}

signed main() {
	freopen("output.txt", "w", stdout);
	int N = gener(100001);
	vector<int> a = gener2(3 * N);

	cout << N << "\n";
	for (int i = 0; i < 3 * N; ++i) {
		cout << a[i] << " ";
		if ((i + 1) % 3 == 0) { cout << "\n"; }
	}
}

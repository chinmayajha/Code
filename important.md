Chicken Mcnugget theorem : "https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem#Origins"
for any two relatively prime positive integers (m, n) the greatest integer that cannot be written in the form (am + bn) for nonnegative integers (a, b) is mn-m-n. 
Converse of the theorem - here are exactly (m - 1)*(n - 1)/2 positive integers which cannot be expressed in the form am + bn. The proof is based on the fact that in each pair of the form (k, mn - m - n - k), exactly one element is expressible. 
-
Harmonic progression sum : https://codeforces.com/blog/entry/55912?#comment-396436
1 / 1 + 1 / 2 + 1 / 3 has a ceil value of log(n)
-
Wilson's Theorem : "https://youtu.be/HqUAUA9u_qs", "https://www.britannica.com/science/Wilsons-theorem"
For any prime number N, => (N - 1)! % N = N - 1
-
Binary Search Codes -
https://leetcode.com/discuss/general-discussion/786126/python-powerful-ultimate-binary-search-template-solved-many-problems
-
Equivalent to Python's split function
vector<string> split(string s, char c) {
    vector<string> a;
    string t = "";
    int n = s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == c) {
            a.emplace_back(t);
            t = "";
        } else t.push_back(s[i]);
    }
    a.emplace_back(t);
    return a;
}
-
Efficient GCD Calc
int gcd(int a, int b) {
    // Source : https://en.algorithmica.org/hpc/analyzing-performance/gcd/
    if (a == 0) return b;
    if (b == 0) return a;
    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int shift = std::min(az, bz);
    b >>= bz;
    while (a != 0) {
        a >>= az;
        int diff = b - a;
        az = __builtin_ctz(diff);
        b = std::min(a, b), a = std::abs(diff);
    }
    return b << shift;
}

Calculating Heights in a Tree using BFS
vector<int> bfs() {
    vector<int> heights(n + 1), vis(n + 1);
    queue<int> qq;
    qq.push(1); qq.push(-1);
    int h = 0;
    while(qq.size() > 1) {
        int cur = qq.front();
        qq.pop();
        if(cur == -1) {
            qq.push(-1);
            h++;
            continue;
        }
        vis[cur] = 1, heights[cur] = h;
        for(auto& i : adj[cur]) {
            if(!vis[i]) qq.push(i);
        }
    }
    return heights;
}
Iterating over boundaries of a grid
for(int x = 0; x < n * m; x++) {
    // Source : https://codeforces.com/blog/entry/96800
    int i = x / m, j = x % m;
    cout << i << ' ' << j << '\n';
    x += (m - 2) * (m != 1 && i != 0 && i != n - 1 && j == 0);
}
Generating random numbers
mt19937 rng(69);
int rnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
#include <random>
int gen_rand(int l = 0, int r = INT_MAX - 100){
    // source : https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(l, r);
    return distrib(gen);
}
#include <random>
vector<int> gen_rand(int n, int l = 0, int r = INT_MAX - 100){
    // source : https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(l, r);
    vector<int> a;
    for (int i = 0; i < n; ++i) a.push_back(distrib(gen));
    return a;
}

// Generating Random Tree of N nodes ==> http://p.ip.fi/f2NJ
// Generating MST using Kruskal's algorithm ==> http://p.ip.fi/EFDi
// LCA in a Tree using Binary Lifting ==> http://p.ip.fi/hKAa
// Dijsktra Impementation (20C Codeforces) ==> http://p.ip.fi/hfDP
// Bellman Ford implementation ==> http://p.ip.fi/l7uH
// Segment Trees basic Build and query 

// Calculating nCr or C(n, r)
int C(int n, int r) {
    if(n < r) return 0;
    if(n == r) return 1;
    if(r > n - r) r = n - r;
    int ans = 1;
    for(int i = 1; i <= r; ++i) ans = (ans * (n - r + i)) / i;
    return ans;
}

// Calculating nCr % p or C(n, r, p)
int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int n, int p) {
    return power(n, p - 2, p);
}

int mul(int x, int y, int p) {
    return x * 1ull * y % p;
}

int divide(int x, int y, int p) {
    return mul(x, modInverse(y, p), p);
}

int C(int n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
    if (n - r < r) return C(n, n - r, p);
    int res = 1;
    for (int i = r; i >= 1; i--) res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}

Subset Sum with Sum <= K
bool subsetsum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][k];
}

Binary Search
// Make check function such that always TTTTTFFFFF
int left = search_begin - 1, right = search_end + 1;
while(right - left > 1) {
    int mid = (left + right) >> 1;
    if(condition) left = mid;
    else right = mid;
}
// After binary search is done
// left is the last true
// right is the first false
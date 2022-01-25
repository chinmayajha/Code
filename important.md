Chicken Mcnugget theorem : "https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem#Origins"
for any two relatively prime positive integers (m, n) the greatest integer that cannot be written in the form (am + bn) for nonnegative integers (a, b) is mn-m-n. 
Consequence of the theorem - here are exactly (m - 1)*(n - 1)/2 positive integers which cannot be expressed in the form am + bn. The proof is based on the fact that in each pair of the form (k, mn - m - n - k), exactly one element is expressible. 
-
Harmonic progression sum : https://codeforces.com/blog/entry/55912?#comment-396436
1 / 1 + 1 / 2 + 1 / 3 has a ceil value of log(n)
-
Wilson's Theorem : "https://youtu.be/HqUAUA9u_qs", "https://www.britannica.com/science/Wilsons-theorem"
For any prime number N, => (N - 1)! % N = N - 1
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
// Generating MST using Kruskal's algorithm ==> http://p.ip.fi/9DWE
// LCA in a Tree using Binary Lifting ==> http://p.ip.fi/pr1u
// Dijsktra Impementation (20C Codeforces) ==> http://p.ip.fi/pRol

// Calculating nCr or C(n, r)
int C(int n, int r) {
    if(n < r) return 0;
    if(n == r) return 1;
    if(r > n - r) r = n - r;
    int ans = 1;
    for(int i = 1; i <= r; ++i) ans = (ans * (n - r + i)) / i;
    return ans;
}

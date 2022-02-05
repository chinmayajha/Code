// https://codebreaker.xyz/problem/yabbitmeetup

#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, y, temp;
vector<vector<pair<int, int>>> adj;
vector<int> mess;

void print() {
    for(int k = 1; k <= n + y; ++k) {
        cout << k << " : ";
        for(auto& i : adj[k]) {cout << i.first << " " << i.second << ", ";} cout << "\n";  
    }
}

void preprocess() {
    adj.resize(n + y + 1);
    mess.resize(y + 1);
    //
    if(n == 1) { // subtask 1
        vector<int> weights(y + 1);
        for(int i = 0; i <= y; ++i) cin >> weights[i] >> weights[i];
        for(int i = 1; i <= y; ++i) cin >> mess[i];
        int sum = accumulate(weights.begin(), weights.end(), 0ll);
        int tempp = LONG_LONG_MAX;
        for(int i = 1; i <= y; ++i) tempp = min((y * weights[i]) + mess[i], tempp);
        cout << sum + tempp;
        exit(0);
    }
    cin >> temp >> temp;
    for(int i = 2, x, z; i <= n + y; ++i) {
        cin >> x >> z;
        adj[i].push_back({x, z});
        adj[x].push_back({i, z});
    }
    for(int i = 1; i <= y; ++i) cin >> mess[i];
    if(y == 1) {
        print();
        // distance from y to everywhere * 2 + mess[y]
        vector<int> dis(n + 2, 100000007), vis(n + 2, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[n + 1] = 0;
        pq.push({dis[n + 1], n + 1});
    
        while((int) pq.size() > 0) {
            int cur = (int) pq.top().second; pq.pop();
            if(vis[cur]) continue;
            vis[cur] = 1;
            for(auto& [node, weight] : adj[cur]) {
                if(dis[node] > dis[cur] + weight) {
                    dis[node] = dis[cur] + weight;
                }
                pq.push({dis[node], node});
            }
        }
        
    }    
}

signed main() {
    cin >> n >> y;
    preprocess(); //subtask 1 included
}
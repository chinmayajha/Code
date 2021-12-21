
#include "bits/stdc++.h"
using namespace std;

const int maxN = 1010;
vector<string> a(maxN);
int ans[maxN][maxN];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
int n, m, k;

bool valid (int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m && a[i][j] != '*';
}

queue<pair<int, int>> q;

int indi = 0, indj = 0;
string fin;
string all = "DLRU";

void solve(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        if(a[i][j] == 'X') {
            indi = i;
            indj = j;
        } else ans[i][j] = -1;
    }
    //Odd length path doesn't exist for return to same cell
    if(k & 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    //BFS for creating answers if possible
    q.push({indi, indj});
    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int z = 0; z < 4; ++z) {
            int dirx = x + dx[z], diry = y + dy[z];
            if(valid(dirx, diry) && ans[dirx][diry] == -1) {
                ans[dirx][diry] = ans[x][y] + 1;
                q.push({dirx, diry});
            }
        }
    }
    //DFS for searching answer created using BFS
    int x = indi, y = indj;
    for(int i = 0; i < k; ++i) {
        int temp = -1;
        for(int z = 0; z < 4; ++z) {
            int dirx = x + dx[z], diry = y + dy[z];
            if(valid(dirx, diry) && i + ans[dirx][diry] + 1 <= k) {
                temp = z;
                break;
            }
        }
        if(temp == -1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        x += dx[temp]; y += dy[temp];
        fin += all[temp];
    }
    cout << fin;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

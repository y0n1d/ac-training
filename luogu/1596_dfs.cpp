// Author: Yoned

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <numeric>

#define endl '\n'
using namespace std;

#ifdef LOCAL
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x);
    void _print() { cerr << "]" << endl; }
    template <typename T, typename... V>
    void _print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _print(v...); }
#else
    #define debug(x...)
#endif



typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9 + 7;

const int N = 1e3 + 10;

int n, m;
int a[N];
int cnt = 0;
int G[N][N];

const int dy[]{0, 0, -1, 1, -1, 1, 1, -1};
const int dx[]{-1, 1, 0, 0, -1, 1, -1, 1};

void dfs(int x, int y) {
    if (G[x][y] == 0 || x < 0 || x >= n || y <0 || y >= m) {
        return;
    }

    G[x][y] = 0;

        for (int i=0; i<8; ++i) {
            
            dfs(x + dx[i], y + dy[i]);
        }
    
}

void solve() {
    char c;
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> c;
            G[i][j] = ((c == 'W') ? 1 : 0);
        }
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (G[i][j] == 1){
                ++ cnt;
                dfs(i, j);
            }
        }
    }
    
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

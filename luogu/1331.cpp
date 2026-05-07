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

int n, m, ships =  0;
int G[N][N];

void dfs(int x, int y) {
    if ( G[x][y] == 0 ) {
        return;
    } else {
        ++ ships;
        int cy = y, cx = x;
        
        while (G[cx][y] == 1 && cx < n) {
            cx ++;
        }
        while (G[x][cy] == 1 && cy < m) {
            cy ++;
        }
        
        // 判断内部是否留空, 顺便填为0
        for (int i = x; i <= cx; ++i) {
            for (int j = y; j <= cy; ++j){
                G[i][j] = 0;
            }
        }

    }
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            char c; cin >> c;
            G[i][j] = ( (c == '#') ? 1 : 0 );
        }
    }

    // 矩形检查
    for (int i=0; i<n-1; ++i) {
        for (int j=0; j<m-1; ++j) {
            if ((G[i][j] + G[i+1][j] + G[i][j+1] + G[i+1][j+1]) == 3) {
                cout << "Bad placement." << endl;
                return;
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if ( G[i][j] == 1) {
                dfs(i, j);
            }
        }
    }

    cout << "There are " << ships << " ships." << endl;
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

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

int n, m, ships =  0, flag = 1;
int G[N][N];

void dfs(int y, int x) {
    if ( G[y][x] == 0 ) {
        return;
    } else {
        int cy = y, cx = x;
        
        while (G[y][cx] == 1 && cx < m) {
            cx ++;
        }
        while (G[cy][x] == 1 && cy < n) {
            cy ++;
        }
        
        // 判断内部是否留空, 顺便填为0
        for (int i = x; i <= cx; ++i) {
            for (int j = y; j <= cy; ++j){
                if (G[i][j] == 1) {
                    G[i][j] = 0;
                } else {
                    cout << "Bad placement." << endl;
                    flag = 0;
                    return;
                }
            }
        } 


        int flag1 = 1;
        // 判断外圈四条是否有相邻
        for (int i = x; i <= cx; ++ i) {
            if ( ((y - 1 >= 0) && G[y - 1][i] == 1) || ((cy + 1 < n) && G[cy + 1][i] == 1)) {
                flag1 = 0;
            } 
        }

        for (int i = y; i <= cy; ++ i) {
            if ( ((x - 1 >= 0) && G[i][x - 1] == 1) || ((cx + 1 < m) && G[i][cx + 1] == 1)) {
                flag1 = 0;
            } 
        }

        debug(flag1)

        // 四角单独判断: 左上，右上，左下，右下
        if ( ((x - 1 >= 0) && (y - 1 >= 0) && (G[x - 1][y - 1] == 0)) ) flag1 = 0;
        if ( ((cx + 1 < m) && (y - 1 >= 0) && (G[cx + 1][y - 1] == 0)) ) flag1 = 0;
        if ( ((x - 1 >= 0) && (cy + 1 < n) && (G[x - 1][cy + 1] == 0)) ) flag1 = 0;
        if ( ((cx + 1 < m) && (cy + 1 < n) && (G[cx + 1][cy + 1] == 0)) ) flag1 = 0;

        if (flag1 == 0){
            flag = 0;
            cout << "Bad placement." << endl;
            return;
        }
        ++ ships;

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
    
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if ( G[i][j] == 1 && flag == 1) {
                dfs(i, j);
            }
        }
    }

    if (flag == 1){
        cout << "There are " << ships << " ships." << endl;
    }
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

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

const int N = 105;

int Map[N][N]; // 地图
int n, m, parent_cot;
int parent[N*N], visited[N*N]; // 祖先列表，访问的时候要取模确认位置

const int direction[4][2] { // 要搜索的四个方向：左下、下、右下、右 (y, x)
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1}
};

// 寻 祖先
int findParent(int i) {
    if ( parent[i] == i ) return i;
    else return parent[i] = findParent(parent[i]); // 路径压缩
}

// x认 y的祖先 为 祖先
void recParent(int x, int y) {
    parent[x] = findParent(y);
}

void dsu(int y, int x) { // (x, y): 当前位置
    if (visited[y * n + x]) return;
    int next_y, next_x;
    debug(x, y);

    // 四个方向扩散
    for (int i=0; i<4; ++i) {
        next_y = y + direction[i][1];
        next_x = x + direction[i][0];
        
        if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n) continue;

        visited[y * n + x] = 1;

        if (Map[y][x] == 1) {
            recParent(next_y * n + next_x, y * n + x);
        }
        dsu(next_y, next_x);
    }
}

// 索引标准为0
void solve() {
    cin >> n >> m; // (y, x)

    // 水1, 地0
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j){
            char k; cin >> k;
            Map[i][j] = (k == 'W' ? 1 : 0);
        }
    }

    // 初始化认祖列表，自己当自己祖先
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            parent[i * n + j] = i * n + j;
        }

    }

    dsu(0, 0);

    // 有多少祖先还是自己的
    parent_cot = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (parent[i * n + j] == i * n + j) ++parent_cot;
        }
    }

    cout << parent_cot << endl;
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

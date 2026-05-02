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

const int N = 5005;

int m, n;
int Map[N][N], p[N], vis[N];
int LRUD[][2]{
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

bool match(int i) {

}

void solve() {
    int x, y, cot;
    cin >> n;
    
    cot = 0;
    for (int i=0; i<n; ++i) {
        cin >> x >> y;
        Map[x][y] = ++cot;
    }

    cot = 0;
    for (int i=0; i<n; ++i) {
        cin >> x >> y;
        Map[x][y] = --cot;
    }
    
    // 绘制邻接矩阵
    // 遍历每个海鸥
    for (int i=0; i<n; ++i) {

        // 海鸥周围
        for (int *move : LRUD) {
            int movedX, movedY;
            movedX = FullMap[i][0] + move[0];
            movedY = FullMap[i][1] + move[1];
            
            // 遍历每个食物, Map[海鸥索引i][食物索引j] = 1
            for (int j=0; j<n; ++j) { 
                if (FoodMap[j][0] == movedX && FoodMap[j][1] == movedY) {
                    Map[i][j] = 1;
                } 
                cout << Map[i][j];
            }
            cout << endl;

        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

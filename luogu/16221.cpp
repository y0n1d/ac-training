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

const int N = 2e5 + 10;



void solve() {
    int n, black[N], blackX[N], blackY[N], white[4], whiteIndex[4];
    
    cin >> n;
    ++ n;

    for (int i=0; i<n; ++i) {

        int x, y;
        cin >> x >> y;
        black[x] = y;
        blackX[i] = x;
        blackY[i] = y;

        //记录谁是白棋 (左右上下的边界)
        if (i == 0) {
            white[0] = x;
            white[1] = x;
            white[2] = y;
            white[3] = y;
        }
    }

    sort(blackX, blackX+n);
    sort(blackY, blackY+n);

    for (int i = 0; i < n-1; ++ i) {
        if (blackX[i] == blackX[i+1] || blackY[i] == blackY[i+1]){
            cout << "NO";
            return;
        }
    }

    // 找到白棋的索引
    whiteIndex[0] = lower_bound(blackX, blackX+n, white[0]) - blackX;
    whiteIndex[1] = lower_bound(blackY, blackY+n, white[1]) - blackY;

    int tryCount = 0;
    int isEnd[4] = {0, 0, 0, 0}; // 左右上下
    while (tryCount != 4) {
        if (whiteIndex[0] == 0) isEnd[0] = 1;
        if (whiteIndex[1] == n-1) isEnd[1] = 1;
        if (whiteIndex[2] == 0) isEnd[2] = 1;
        if (whiteIndex[3] == n-1) isEnd[3] = 1;
        
        // 判断边界是否都可到达
        int allEnd = 1;
        for (int i : isEnd) {
            if (i == 0){
                allEnd == 0;
                break;
            }
        } if (allEnd == 1) {
            cout << "YES" << endl;
            return;
        }

        for (int i=0; i<4; ++i) {
            
            // 判断是不是边界
            if (isEnd[i] == 1){
                ++ tryCount;
                continue;
            }
            // 后续的一定未抵达边界
            
            // 判断左
            if (i == 0){

            }
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

//Wed Apr 29 02:47:27 PM CST 2026
// Author: AepZ

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

const int N = 1e4 + 1;

int n, m;
set<int> levels[N];


void solve() {
    cin >> n >> m;
    
    //初始化层级, 所有站台加入 levels[1] 的集合
    for (int i=1; i<m+1; ++ i){
        levels->insert(i);
    }
    
    //主循环
    for (int i = 1; i < m+1; ++ i){
        int k;
        cin >> k;

        //每层车站层级输入入口
        set<int> bigger, smaller;
        for (int j = 1; j < k+1; ++ j){
            int k; cin >> k;
            bigger.insert(k); 
        }
        
        //将集合中最小到最大值的所有加入到 smaller 中，然后保留较小值
        for (int i = *bigger.begin(); i < *bigger.rbegin()+1; ++ i){
            smaller.insert(i);
        }
        for (const auto& val: bigger){
            smaller.erase(val);
        }
        
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

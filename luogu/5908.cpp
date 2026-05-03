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

int n, m, d, qq;
vector<int> a[N];

void dfs(int c, int p, int dep) { //当前，父，深度
    if (dep > d) return;
    if (c != 1) ++qq;

    for (int i : a[c]) {
        if (i != p) dfs(i, c, dep + 1);
    }
}

void solve() {
    cin >> n >> d;

    for (int i=0; i<n-1; ++i) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1, 0, 0);
    cout << qq << endl;

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

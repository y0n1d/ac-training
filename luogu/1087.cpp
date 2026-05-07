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
#include <stack>

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

int n, m, k;
int a[N];

int dfs(int l, int r) {
    if (l == r) {
        cout << (a[l] == 1 ? 'B' : 'I');
        return (a[l]);
    }

    int mid = (l + r) >> 1;
    int left = dfs(l, mid);
    int right = dfs(mid + 1, r);

    int mid_val = left | right;
    if (mid_val == 1) cout << 'B';
    else if (mid_val == 2) cout << 'I';
    else cout << 'F';

    return mid_val;
}

string s;
void solve() {
    cin >> n >> s;

    for (int i=0; i<(1 << n); ++i) {
        a[i] = (s[i] == '0' ? 1 : 2);
    }

    dfs(0, (1 << n) - 1);
    cout << endl;

}

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

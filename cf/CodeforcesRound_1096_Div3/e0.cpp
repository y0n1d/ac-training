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

int n, m;
int a[N], mf[N]; // minimum suffix



void solve() {
    int a_sum = 0;

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        a_sum += a[i];
    }

    mf[n-1] = a[n-1];
    a_sum -= mf[n-1];

    for (int i=n-2; i>=0; -- i) {
        mf[i] = min(a[i], mf[i+1]);
        a_sum -= mf[i];
    }

    int mx = 1, pre=-1, cmx=1;
    for (int i = 0; i < n; ++ i) {
        if (pre == mf[i]) ++cmx;
        else {
            mx = max(mx, cmx);
            cmx = 1;
        }
        pre = mf[i];
    }
    // debug(a_sum, max(mx, cmx));
    cout << a_sum + max(mx, cmx) - 1 << endl;
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

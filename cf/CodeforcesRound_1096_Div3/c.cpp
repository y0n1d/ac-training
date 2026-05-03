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

int a[N];



void solve() {
    int n;
    int l[N], r[N], m[N], six[N];
    int il = 0, ir = 0, im = 0, isix = 0;

    cin >> n;

    int num;
    for (int i=0; i<n; ++i) {
        cin >> num;
        if (num % 6 == 0){
            six[isix] = num;
            ++ isix;
        } else if (num % 2 ==0) {
            l[il] = num;
            ++ il;
        } else if (num % 3 ==0) {
            r[ir] = num;
            ++ ir;
        } else {
            m[im] = num;
            ++ im;
        }
    }

    for (int i=0; i<isix; ++i) cout << six[i] << ' ';
    for (int i=0; i<il; ++i) cout << l[i] << ' ';
    for (int i=0; i<im; ++i) cout << m[i] << ' ';
    for (int i=0; i<ir; ++i) cout << r[i] << endl;
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

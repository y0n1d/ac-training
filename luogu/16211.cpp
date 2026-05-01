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
int a[N];



void solve() {
    string a = "ECUST";
    int n = 5;
    int b;
    int j;

    for (int i = 0; i < (1 << n); ++i) {
        for ( j = n - 1; j >= 0; --j) {
            b = ((i >> j) & 1); 
            cout << (char)(a[n-j-1] + (b==1 ? 32 : 0));
        }
        cout << endl;
    } 
}

int main() { 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

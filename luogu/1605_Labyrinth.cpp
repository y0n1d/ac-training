// Author: Y0n1d

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

const int N = 100;
int n, m;
int a[N];

//----------------------------------------------------------------------
int l, w, t, Sx, Sy, Fx, Fy;
int urea[100][100];

const int moveTo[][2] = {
    {-1, 0},
    {1,  0},
    {0, -1},
    {0,  1}
};

int dfs(int Cx, int Cy) {
    int found = 0;
    if (Cx == Fx && Cy == Fy) return 1;
    
    for (int i=0; i<4; i++) {
        int Nx = Cx + moveTo[i][0];
        int Ny = Cy + moveTo[i][1];

        if (Nx < 1 || Nx > l || Ny < 1 || Ny > w || urea[Nx][Ny]==1) {
            continue;
        } else {
            debug(Nx, Ny);
            urea[Nx][Ny] = 1;
            found += dfs(Nx, Ny);
            urea[Nx][Ny] = 0;
        }
    }

    return found;
}

void solve() {
    cin >> l >> w >> t
    >> Sx >> Sy >> Fx >> Fy;
    
    debug(l, w, t);
    debug(Sx, Sy, Fx, Fy);

    for (int i=0; i<t; ++i) {
        debug("bk in");
        int Bx, By;
        cin >> Bx >> By;
        urea[Bx][By] = 1;
    };
    urea[Sx][Sy] = 1;

    cout << dfs(Sx, Sy) << endl;
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

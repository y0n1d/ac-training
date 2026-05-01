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

const int N = 2e5 + 10;

int n, m;
int a[N];
struct Point { 
    int x, y; 

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};


vector<Point> bk;
int l, w, t, //长 宽 障碍数
    Sx, Sy, Fx, Fy, // 起点xy 终点xy
    trails = 0;

Point moveTo[4] = {
    {0, -1},
    {0,  1},
    {-1, 0},
    {1,  0}
};

void dfs(vector<Point> traces, Point current_pos) {
    debug(current_pos.x); debug(current_pos.y);
    debug(Fx); debug(Fy);
    if (current_pos.x == Fx && current_pos.y == Fy) { ++trails; return; }

    debug("inter");
    
    vector<Point> next_traces = traces;
    for (Point m : moveTo) {
        Point next_pos;
        next_pos.x = current_pos.x + m.x;
        next_pos.y = current_pos.y + m.y;

        debug(next_pos.x);
        debug(next_pos.y);

        debug(find(traces.begin(), traces.end(), next_pos) == traces.end());
        debug(find(bk.begin(), bk.end(), next_pos) == bk.end());

        if (
            find(traces.begin(), traces.end(), next_pos) == traces.end() &&
            find(bk.begin(), bk.end(), next_pos) == bk.end() &&
            next_pos.x+1 < 0 && next_pos.x >= w &&
            next_pos.y+1 < 0 && next_pos.y >= l
        ) {
            debug("+-*/");
            next_traces.push_back(next_pos);
            dfs(next_traces, next_pos);
        } else return;
    }
}

void solve() {
    cin >> l >> w >> t;
    cin >> Sx >> Sy >> Fx >> Fy;
    for (int i=0; i<t; ++i) {
        Point j;
        cin >> j.x >> j.y;
        bk.push_back(j);
    };  
    vector<Point> traces;
    Point start_pos;start_pos.x=Sx;start_pos.y=Sy;

    debug(l, w, t);
    debug(Sx, Sy, Fx, Fy);
    for (int i=0; i<t; i++) cout << bk[i].x << ',' << bk[i].y << endl;
    debug("========================================================");
    dfs(traces, start_pos);
    cout << trails;
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

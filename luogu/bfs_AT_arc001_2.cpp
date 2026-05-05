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
int dist[100], offset = 20;
queue<int> q;
const int ops[6] = {
    1, -1, 5, -5, 10, -10
};



void solve() {
    cin >> n >> m;

    if (n == m) {
        cout << 0 << endl;
        return;
    } else {

        for (int i=0; i<100; ++i) {
            dist[i] = -1;
        }

        q.push(n);
        dist[n + offset] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i=0; i<6; ++i) {
                int next_temp = curr + ops[i];
                int next_idx = next_temp + offset;

                if (next_idx >= 0 && next_idx < 100) {
                    if (dist[next_idx] == -1) { // 还没有被访问
                        dist[next_idx] = dist[curr + offset] + 1;

                        if (next_temp == m) {
                            cout << dist[next_idx] << endl;
                            return;
                        }
                        q.push(next_temp);
                    }
                }
            }

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

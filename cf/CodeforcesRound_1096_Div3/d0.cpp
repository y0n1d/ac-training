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

vector<int> v;
int m,n;
int a[N];

int solve(int l, int r) {
    set<int> nums;
    for (int i=0; i<n+1; ++i) nums.insert(i);
    
    while (l >= 0 && r < 2 * n && v[l] == v[r]){
        nums.erase(v[l]);
        -- l, ++ r;
    }
    
    return *nums.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        v = vector<int> (2*n);
        for (auto &i : v) cin >> i;

        int l=-1, r=-1;
        for (int i=0; i < n*2; ++i) {
            if (v[i] == 0) {
                if (~l) r = i;
                else l = i;
            }
        }
        
        cout << max({solve(l, l), solve((l+r)/2, (l+r+1)/2), solve(r, r)}) << endl;
    }
    return 0;
}

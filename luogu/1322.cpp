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
#include <stack>
#include <stdio.h>

#define endl '\n'
using namespace std;

#ifdef LOCAL
    #define debug(x...) cerr << "[" << #x << "] = -> "; _print(x);
    void _print() { cerr << " <-" << endl; }
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

int calcDis() {
    string mode;
    int num, dis = 0, next;

    while(cin>>mode){
        debug(mode);

        if (mode == "]") return 0;

        if(mode=="FD"){
            cin >> num;
            dis += num;
            next = getchar();
        }else if(mode=="BK"){
            cin >> num;
            dis -= num;
            next = getchar();
        }else if(mode=="REPEAT"){
            cin >> num;
            getchar();//[
            dis += num * calcDis();
            next = getchar();//]
        }

        if (next == ']') break;
    }

    return dis;
}

void solve() {    
    cout << abs(calcDis());
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
// Author: AepZ

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
#define fi first
#define se second
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

const int N = 2e5 + 10;

int n, m;

void solve() {
    cin>>n;
    int wx, wy;
    cin>>wx>>wy;

    vector<pii> cars;

    cars.push_back({wx, wy});

    int x, y;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        cars.push_back({x, y});
    }

    // 国王也加进去了
    n=n+1;

    vector<pii> horizontal=cars, vertical=cars;
    sort(horizontal.begin(), horizontal.end(), [](const pii& a, const pii& b){return a.first<b.first;});
    sort(vertical.begin(), vertical.end(), [](const pii& a, const pii& b){return a.second<b.second;});
    
    for(int i=1;i<n;++i){
        if(horizontal[i].first == horizontal[i-1].first ||
            vertical[i].second == vertical[i-1].second){
            cout<<"NO"<<endl;
            return;
        }
    }

    // 找到第一个 X 坐标大于国王的黑车，这就是向右的指针 r
    int r = lower_bound(horizontal.begin(), horizontal.end(), pii(wx, 0), 
            [](const pii& a, const pii& b){ return a.fi < b.fi; }) - horizontal.begin();
    int l = r - 1; // 左指针自然就是 r 的前一个

    // 找到第一个 Y 坐标大于国王的黑车，这就是向上的指针 d
    int d = lower_bound(vertical.begin(), vertical.end(), pii(0, wy), 
            [](const pii& a, const pii& b){ return a.se < b.se; }) - vertical.begin();
    int u = d - 1; // 向下的指针自然就是 d 的前一个


    
    while(true){
        int flag = 0;
        int nl=l, nr=r, nu=u, nd=d;

        if(0<=l && l<n && (0<=u && u<n && horizontal[l] == vertical[u] || 0<=d && d<n && horizontal[l] == vertical[d])){
            nl=l-1;
            flag=1;
        }

        if(0<=r && r<n && (0<=u&&u<n && horizontal[r] == vertical[u] || 0<=d&&d<n && horizontal[r] == vertical[d])){
            nr = r+1;
            flag=1;
        }

        if(0<=u && u<n && (0<=l&&l<n && vertical[u] == horizontal[l] || 0<=r&&r<n && vertical[u] == horizontal[r])){
            nu=u-1;
            flag=1;
        }

        if(0<=d&& d<n && (0<=l&&l<n && vertical[d] == horizontal[l] || 0<=r&&r<n && vertical[d] == horizontal[r])){
            nd=d+1;
            flag=1;
        }
        
        l=nl, r=nr,u=nu,d=nd;
        if(flag==0){
            break;
        }
    }

    if(l==-1 && r==n && u==-1 && d==n){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 

    int t = 1;
    cin >> t;  // 多测清空
    while (t--) {
        solve();
    }
    return 0;
}
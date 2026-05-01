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

const int INF = 0x3f3f3f3f;

// const int N = 2e5 + 10;

int n, m;
set<pii> jvx;
set<pii> jvy;



void solve() {
    jvx.clear();
    jvy.clear();

    cin >> n;

    int x, y;

    int wx, wy;
    cin>>wx>>wy;
    jvx.insert({wx, wy});
    jvy.insert({wy, wx});

    for(int i=0;i<n;++i){
        cin>>x>>y;
        jvx.insert({x, y});
        jvy.insert({y, x});
    }

    // 判断没有相互保护的车
    int prev_x=INF;
    for(auto&cur_pair:jvx){
        if(cur_pair.first==prev_x){
            cout<<"NO"<<endl;
            return;
        }
        prev_x = cur_pair.fi;
    }

    int prev_y=INF;
    for(auto&cur_pair:jvy){
        if(cur_pair.first==prev_y){
            cout<<"NO"<<endl;
            return;
        }
        prev_y = cur_pair.fi;
    }

    // 找到自己坐标的索引
    // int wx_idx=distance(jvx.begin(), jvx.find({wx, wy}));
    // int wy_idx=distance(jvy.begin(), jvy.find({wy, wx}));

    // debug(wx_idx, wy_idx);
    int Left = 1, Right = 1, Up = 1, Down = 1;

    // for(auto&x:jvx){
    //     cout<<x.first<<" ";
    // }
    // cout<<endl;
    // for(auto&x:jvy){
    //     cout<<x.first<<" ";
    // }
    // cout<<endl;

    auto lx = jvx.find({wx, wy});
    if(lx != jvx.begin()){
        lx = prev(lx);
    }else{
        Up = 0;
    }
    
    auto ly = jvy.find({wy, wx});
    if(ly != jvy.begin()){
        ly = prev(ly);
    }else{
        Left = 0;
    }
    
    auto rx = jvx.find({wx, wy});
    if(rx != prev(jvx.end())) {
        rx = next(rx);
    }else{
        Down = 0;
    }

    auto ry = jvy.find({wy, wx});
    if(ry != prev(jvy.end())){
        ry = next(ry);
    }else{
        Right = 0;
    }

    int fail_count=0;

    int cnt=0;
    while(fail_count<4){
        if(cnt==10){
            cout<<"NO"<<endl;
            return;
        }
        cnt++;
        if(Left+Right+Up+Down == 0){
            cout<<"YES"<<endl;
            return;
        }
        if(Up == 1){
            debug("Enter Up");
            if( (*lx).second == (*ly).first || (*lx).second == (*ry).first ){
                debug("Up Can");
                if(lx == jvx.begin()){
                    debug("Upest")
                    Up = 0;
                }else{
                    lx = prev(lx);
                    fail_count=0;
                    debug("Up 0")
                }
            }
        }else{
            ++fail_count;
        }
        debug("up", fail_count);

        if(Down == 1){
            if( (*rx).second == (*ly).first || (*rx).second == (*ry).first ){
                if(rx == prev(jvx.end())) {
                    Down = 0;
                }else{
                    rx = next(lx);
                    fail_count=0;
                    debug("down 0")
                }
            }
        }else{
            ++fail_count;
        }

        if(Left == 1){
            if( (*ly).second == (*lx).first || (*ly).second == (*rx).first ){
                if(ly == jvy.begin()){
                    Left = 0;
                }else{
                    ly = prev(ly);
                    fail_count=0;
                    debug("left 0")
                }
            }
        }else{
            ++fail_count;
        }

        if(Right == 1){
            if( (*ry).second == (*lx).first || (*ry).second == (*rx).first ){
                if(ry == prev(jvy.end())) {
                    Right = 0;
                }else{
                    ry = next(ry);
                    fail_count=0;
                    debug("right 0")
                }
            }
        }else{
            ++fail_count;
        }

        debug(Left, Right, Up, Down, fail_count);
    }
    cout<<"NO"<<endl;
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
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
const int N = 1e5 + 10;


pair<int, int> verify(int x){
    if(x == 1){
        return {0, 1};
    }
    
    int base = 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            base = i;
            break;
        }
    }
    // 如果 base 还是 0，说明 x 没被任何数整除，x 本身就是质数
    if (base == 0) {
        base = x;
    }

    // 去除x的所有最小质因子
    while(x % base == 0){
        x /= base;
    }

    // 如果此时x不为1，则说明还有其他质因子
    return {x != 1, base};
}

int n;
int a[N];

void solve(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }

    int flag = 0;
    for(int i=1;i<n;++i){
        if(a[i-1] > a[i]){
            flag=1;
            break;
        }
    }

    if(flag == 0){
        cout<<"Bob"<<endl;
        return ;
    }


    for(int i=0;i<n;++i){
        int x = a[i];
        auto res = verify(x);
        int istrue = res.first, base = res.second;
        // debug(istrue, base)
        if(istrue){
            cout<<"Alice"<<endl;
            return ;
        }else{
            // 将 a ^ b 化为 a， 相当于无法再次拆分
            a[i] = base;
        }
    }

    for(int i=1;i<n;++i){
        if(a[i-1] > a[i]){
            cout<<"Alice"<<endl;
            return ;
        }
    }

    cout<<"Bob"<<endl;
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

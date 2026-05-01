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
bool found = false;
vector<string> path;

void dfs(vector<int> nums) {
    if (found) return;
    
    if (nums.size() == 1) {
        if (nums[0] == 24) {
            found = true;
            for (string s : path) cout << s << endl;
        }
        return;
    }


    for (int i=0; i<nums.size(); ++i) {
        for (int j=0; j<nums.size(); ++j) {
            if (i == j) continue;

            int a=nums[i], b=nums[j];
            if (a < b) continue;

            vector<int> next_nums;
            for (int k=0; k<nums.size(); ++k)
                if (k!=i && k!=j) next_nums.push_back(nums[k]);

            for (int op=0; op<4; ++op) {
                int res;
                string op_str;

                if     (op == 0) {res = a+b; op_str="+";}
                else if(op == 1) {res = a-b; op_str="-";}
                else if(op == 2) {res = a*b; op_str="*";}
                else if(op == 3) {
                    if ( b == 0 || a%b != 0 ) continue;
                        res = a/b; op_str="/";
                }

                vector<int> add_res = next_nums;
                add_res.push_back(res);

                path.push_back(to_string(a) + op_str + to_string(b) + "=" + to_string(res));

                dfs(add_res);
                if (found) return;
                path.pop_back();
            }

        }
    }

}

void solve() {

    vector<int> nums(4);
    for (int i=0; i<4; i++) cin >> nums[i];
    dfs(nums);

    if (!found) cout << "No answer!" << endl;

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
//Mon Apr 27 09:27:11 PM CST 2026
//1:Mon Apr 27 11:45:12 PM CST 2026

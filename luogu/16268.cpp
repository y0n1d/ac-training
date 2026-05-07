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

struct Node {
    int include = 0; // 子树中完整指令的数量
    int end = 0; // 该节点是否上某个命令的结尾
    string word = ""; // 若为完整指令，记录
    vector<Node> child;
    
    Node() = default;                    // 不提前resize
    
    Node* get_child(unsigned char c) {   // 懒创建
        if (child.empty()) {
            child.resize(128);
        }
        return &child[c];
    }
};


void solve() {
    Node root;
    cin >> n >> m;

    for (int i=0; i<n; ++i) {

        Node* now = &root;
        string command;
        cin >> command;

        for (char c : command) {
            Node* next = now -> get_child((u_char)c);
            now -> include++;
            now = next;
        }

        now -> include++; // 终点也算
        now -> end++;
        now -> word = command;
    }

    
    for (int i=0; i<m; ++i) {

        Node *now = &root;
        string command;
        cin >> command;
        bool flag = true;

        for (char ch : command) {
            u_char c = ch;
            if (now -> child.empty() || now -> child[c].include == 0) {
                cout << "unknown" << endl;
                flag = false;
                break;
            }
            now = &(now -> child[c]);
        }
        if (!flag) continue;

        // 判断无匹配和多匹配的情况
        if (now -> include == 0) {
            cout << "unknown" << endl;
            continue;
        }else if (now -> include > 1) {
            cout << "ambiguous" << endl;
            continue;
        }

        while (now -> end == 0) {
            for (int j = 0; j< 128; ++j) {
                if (!now -> child.empty() && now -> child[j].include >  0) {
                    now = &(now -> child[j]);
                    break;
                }
            }
        }

        cout << now -> word << endl;
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

#include <bits/stdc++.h>
using namespace std;

int n, t=0;

int main() {
    cin >> n;
    while(n) t=t*10 + n%10, n/=10;
    cout << t;
    cout << "\n";
    return 0;
}
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, q[N];

void quickSort( int q[], int l, int r) {
    if ( l >= r ) return;
    
    int x = q[l], i = l, j = r;
    
    
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; ++i) scanf("%d", &q[i]);
    quickSort(q, 0, n-1);
    for (int i=0; i<n; ++i) cout << q[i];

    return 0;
}
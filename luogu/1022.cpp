#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;
    double a = 0, b = 0, n = 0, sn = 1, sd = 1;
    bool hasN = false; char v;

    for (char c : s + "+") {
        if (isdigit(c)) {
            n = n * 10 + (c - '0');
            hasN = true;
        } else if (isalpha(c)) {
            v = c;
            a += sd * sn * (hasN ? n : 1);
            n = 0; hasN = false;
        } else {
            b += sd * sn * n;
            n = 0; hasN = false;
            if (c == '=') { sd = -1; sn = 1; } 
            else sn = (c == '-' ? -1 : 1);
        }
    }

    double x = -b / a;
    printf("%c=%.3f\n", v, x);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
double ans;
int n, i;//i要存着！！！
int main()
{
	cin >> n;//输入
	for(i = 1; ans <= n;i++)
	{
        ans += 1.0 / i;//模拟
	}
	cout << i - 1;//注意是i - 1，此时的i已经“++”
	return 0;
}

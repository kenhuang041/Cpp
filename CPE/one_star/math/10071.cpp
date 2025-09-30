// https://zerojudge.tw/ShowProblem?problemid=d226
// 給定速度v跟時間t，求2t時的位移
// 送分題 直接輸出 2*a*b
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pci pair<char,int> 
#define int long long 
#define F first
#define S second
#define N 65536

signed main() { 
	IO;
	double a,b;
	while(cin >> a >> b) {
		cout << 2 * a * b << "\n";
	}
	return 0;
}

// https://zerojudge.tw/ShowProblem?problemid=d186
// 求範圍內有幾個完全平方數
// 定義a[]，如果n是完全平方數則a[n] = 1
// 用 accumulate 求範圍內完全平方數總和
#include <bits/stdc++.h>
using namespace std;
#define piii pair<pair<int,int>,int>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 100005
#define F first
#define S second


signed main() {
    IO;
    int p=1;
    int a[N];
    memset(a,0,sizeof(a));
    while(p*p <= N) {
      	a[p*p] = 1;
      	p++;
  	}
  	
  	int b,e;
  	while(cin >> b >> e && b && e) {
    		int sum = accumulate(a+b,a+e+1,0); //begin, end, 初值
    		cout << sum << endl;
  	}
    return 0;
}

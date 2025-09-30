// https://zerojudge.tw/ShowProblem?problemid=c022
// 求 [l,r] 內所有基數和
// 用前綴和就可以了
// *要注意取區間值的時候不要超出邊界(小於0)
#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double,double>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 10005
#define F first
#define S second

signed main() {
    IO;
    int a[105];
    a[0] = 0;
    for(int i=1; i<=100; i++) {
      	if(i%2 == 1) a[i] = a[i-1] + i;
      	else a[i] = a[i-1];
  	}
	
	  int n,p,q,t=1;
    cin >> n;
    for(int i=0; i<n; i++) {
      	cin >> p >> q;
      	cout << "Case " << t++ << ": " << (a[q] - a[((p-1 < 0) ? 0 : p-1)]) << "\n";
  	}
    
    return 0;
}

// https://zerojudge.tw/ShowProblem?problemid=e510
// 直接用無窮等比級數求解即可
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

signed main() { 
	IO;
	int s,n,i;
	double p;
	cin >> s;
	
	while(s--) {
		cin >> n >> p >> i;
		//   p*(1-p)^n-1
		// ---------------
		//   1-(1-p)^N
		
		double ans = (p*(pow((1.0-p),i-1))) / (1-(pow((1.0-p),n)));
		cout << fixed << setprecision(4) << ans << "\n"; // 小數點後四位
	}
	
	return 0;
}

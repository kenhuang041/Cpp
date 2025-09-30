// https://zerojudge.tw/ShowProblem?problemid=e510
// 假設共有n個玩家玩骰子 則p代表擲出某個面的機率(6面骰就是1/6)
// 遊戲由玩家1開始 至玩家n結束
// 求玩家i獲勝的機率 (玩家i擲出其目標面)
// (目標面不會定義，因為擲出每個面的概率相同)

// 直接帶無窮等比級數 S = a0/(1-r) 求解
// 如果勝利機率是p 則輸掉的機率就是 1-p
// a0(首項) = 玩家i勝利且前面i-1位玩家輸 = p * ((1.0-p)^(i-1));
// r(公比) = 全部玩家都輸掉 = 1 - ((1.0-p)^n)
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
		cout << fixed << setprecision(4) << ans << "\n";
	}
	
	return 0;
}

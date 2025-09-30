// https://zerojudge.tw/ShowProblem?problemid=a134
// 以費式數列為基底的二進制
// 用前綴和快速球費式數列 再由大到小遞減數字直至1
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define N 55

signed main() {
    IO;
    int dp[N],n,m,idx = 2;
    memset(dp,0,sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    while(1) {
    	dp[idx] = dp[idx-1] + dp[idx-2];
    	if(dp[idx] > 100000000) break;
    	idx++;
	}

	cin >> n;
	for(int i=0,num,tmp,j; i<n; i++) {
		cin >> num;
		j = idx;
		while(dp[j]>num) j--;
		
		tmp = 0;
		m = num;
		string ans = "";
		
		while(j != 1) {
			if(num-dp[j] >= 0) {
				num -= dp[j];
				ans += "1";
				tmp=1;
			}
			else if(tmp) ans += "0";
			j--;
		}
		
		cout << m << " = " << ans << " (fib)\n";
	}
    return 0;
}

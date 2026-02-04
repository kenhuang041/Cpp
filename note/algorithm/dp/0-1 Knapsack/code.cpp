#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1e9 + 7;

signed main() {
	int x,t = 0;
	cin >> x;
	t = (x*(x+1))/2;
	if(t%2 == 1) {
		cout << "0\n";
		return 0;
	}
	
	vector<int> dp(t+1, 0);
	dp[0] = 1;
	for(int i=1; i<x; i++) {
		for(int j=t/2; j>=i; j--) {
			dp[j] = (dp[j] + dp[j-i]) % MOD;
		}
	}
	
	cout << dp[t/2];
	return 0;
}
 

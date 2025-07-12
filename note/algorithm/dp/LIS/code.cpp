#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,mx=0;
	cin >> n;
	int a[n],dp[n];
	vector<int> ans;
	for(int i=0; i<n; i++) cin >> a[i];
	fill(dp,dp+n,1);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(a[j] < a[i]) {
				dp[i] = max(dp[j]+1,dp[i]);
			}
		}
	}
	for(int i=0; i<n; i++) mx = max(mx,dp[i]);
	cout << mx;
	return 0;
} 

/* 測資:
8
10 9 2 5 3 7 101 18
*/

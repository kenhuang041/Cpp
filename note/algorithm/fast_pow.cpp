// https://zerojudge.tw/ShowProblem?problemid=e827
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define int long long
#define N 1000000007
int n,l,p;

int fastpow(int a,int b) {
	if(b == 0) return 1;
	int ans = fastpow(a,b>>1); // a^(b/2)
	if(b%2 == 0) return (ans*ans)%N; // 如果 b 是偶數 -> a^b = (a^(b/2))^2 
	return (ans*ans*a)%N; // 如果 b 是基數 -> a^b = (a^(b/2))^2 * a 
}

signed main() {
	IO;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> l;
		p = fastpow(2,l-1);
		cout << p << "\n";
	}
	return 0;
}

// https://zerojudge.tw/ShowProblem?problemid=e579
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define IsHolidays ((j%7 == 6) || (j%7 == 0))

signed main() { 
	IO;
	int t,n,p,tmp;
	cin >> t;
	
	for(int i=0; i<t; i++) {
		cin >> n >> p;
		int ans = 0;
		vector<int> v(n+5,0);
		
		for(int k=0; k<p; k++) {
			cin >> tmp;
			
			for(int j=1; j<=n; j++) 
				if(j%tmp == 0 && !IsHolidays) v[j]=1;
		}
		
		for(auto it : v) ans += it;
		cout << ans << "\n";
	}
	return 0;
}

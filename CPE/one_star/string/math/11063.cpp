// https://zerojudge.tw/ShowProblem?problemid=d123
// 數列所有的 bi + bj （i <= j）皆不相等
// 用巢狀for取得所有 bi + bj 接著將所有項排序
// 如果沒有連續的項目 則為B2-Sequence
// *特別注意 數列必須符合這個條件: 1<= b1 < b2 < b3 ...
//  所以在輸入部分需要比較多的判斷
#include <bits/stdc++.h>
using namespace std;
#define piii pair<pair<int,int>,int>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 505
#define F first
#define S second


signed main() {
    IO;
    int n,t=1;
    while(cin >> n && n) {
    	int a[n],ok = 1,prev = 0;
    	cin >> a[0] >> a[1];
    	if(a[0] > a[1]) ok = 0;
    	for(int i=2; i<n; i++) {
      		cin >> a[i];
      		if(a[i] <= a[i-1]) ok = 0;
  		}
  		
      if(a[0] < 1 || !ok) {
      	cout << "Case #" << t++ << ": It is not a B2-Sequence.\n\n";
      	continue;
  		}
  		
      vector<int> v;
      for(int i=0; i<n; i++) {
      	for(int j=i; j<n; j++) {
      	  	v.push_back(a[i] + a[j]);
  			}
  		}
  		sort(v.begin(),v.end());
  		
  		prev = INT_MAX;
  		ok = 1;
  		for(auto it : v) {
  			if(it == prev) {
  				ok = 0;
  				break;
  			}
  			prev = it;
  		}
  		
  		if(ok) cout << "Case #" << t << ": It is a B2-Sequence.\n\n";
  		else cout << "Case #" << t << ": It is not a B2-Sequence.\n\n";
  		t++;
  	}
    return 0;
}

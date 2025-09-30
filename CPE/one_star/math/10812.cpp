// https://zerojudge.tw/ShowProblem?problemid=c004
// 給定a,b的總和及差值 問有沒有滿足此條件a,b
// for遍歷每種a,b組合 看有沒有符合條件的
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
    int n;
    cin >> n;
    for(int i=0,a,b,bl; i<n; i++) {
    	cin >> a >> b;
    	bl = 0;
		
    	for(int j=0; j<=a; j++) {
    		if(abs(a-j - j) == b) {
    			cout << a-j << " " << j << "\n"; 
    			bl = 1;
    			break;
  			}
  		}
		
  		if(!bl) cout << "impossible\n";
  	}
    return 0;
}

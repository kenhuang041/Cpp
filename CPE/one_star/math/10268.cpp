// https://zerojudge.tw/ShowProblem?problemid=f444
// 給定x和方程式的係數 求方程式微分後代入x的結果
// 知道微分的概念就做得出來
// 2x^3 = 6x^2
#include <bits/stdc++.h>
using namespace std;
#define pdd pair<double,double>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 10005
#define F first
#define S second

int fastpow(int x,int p) {
	if(p == 0) return 1;
	int ans = fastpow(x,p/2);
	if(p%2 == 0) return (ans*ans);
	else return (ans*ans*x);
}

signed main() {
    IO;
    int n;
    while(cin >> n) {
    	cin.ignore();
    	string s,tmp;
    	vector<int> v;
    	int ans = 0;
    	getline(cin,s);
    	stringstream ss(s);
    	
    	while(ss >> tmp) v.push_back(stoll(tmp));
    	
    	for(int i=v.size()-1; i>=0; i--) {
    		if(i == v.size()-1) continue;
    		if(i == v.size()-2) ans += v[i];
    		else {
    			ans += ((v[i]*(v.size()-i-1)) * fastpow(n,(v.size()-i-2)));
			  }
		  }
		
		  cout << ans << "\n";
	  }
    return 0;
}

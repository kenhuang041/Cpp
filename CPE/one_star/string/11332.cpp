// https://zerojudge.tw/ShowProblem?problemid=c813
// 題目敘述夠清楚 這邊就不細說了
// 字串遞迴求解即可
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 36
#define F first 
#define S second 

string f(string s) {
	if(s.size() == 1) return s;
	else {
		int t=0;
		for(auto it : s) t += (it-'0');
		return f(to_string(t));
	}
}

signed main() {
    IO;
    string s;
    while(cin >> s) {
    	if(s == "0") break;
    	cout << f(s) << "\n";
	}
    return 0;
}

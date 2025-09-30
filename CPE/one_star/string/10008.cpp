// https://zerojudge.tw/ShowProblem?problemid=c044
// 統計各單字(大寫)的出現次數
// 用map統計次數就行

#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pci pair<char,int>
#define int long long
#define F first
#define S second
#define N 55

bool cmp(pci a,pci b) {
	if(a.S != b.S) return a.S > b.S;
	else return a.F < b.F; 
}

signed main() {
    IO;
    map<char,int> mp;
    string s;
    int n;
    cin >> n;
    cin.ignore();
    
    while(n--) {
		  getline(cin,s);
    	for(auto ch : s) mp[toupper(ch)]++;
	  }
	
  	vector<pci> v(mp.begin(), mp.end());
  	sort(v.begin(),v.end(),cmp); 
  	
  	for(auto it : v) {
  		if(it.F >= 'A' && it.F <= 'Z') 
  			cout << it.F << " " << it.S << "\n"; 
  	}
    
    return 0;
}

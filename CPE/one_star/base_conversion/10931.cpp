// https://zerojudge.tw/ShowProblem?problemid=a132
#include <bits/stdc++.h>
using namespace std;
#define piii pair<pair<int,int>,int>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 10005
#define F first
#define S second

signed main() {
    IO;
    int n;
    while(cin >> n&&n) {
    	bitset<32> bt(n);
    	string ans = bt.to_string();
    	int i=0,t=0;
    	
    	cout << "The parity of ";
    	while(ans[i] == '0') i++;
    	for(int k=i; k<ans.size(); k++) {
    		cout << ans[k];
    		if(ans[k] == '1') t++;
		}
		cout << " is " << t << " (mod 2).\n";
		
	}
    return 0;
}

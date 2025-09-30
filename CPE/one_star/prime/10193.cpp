// https://zerojudge.tw/ShowProblem?problemid=d306
#include <bits/stdc++.h>
using namespace std;
#define pis pair<int,string>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 10005
#define F first
#define S second
#define OUT (q<0 || q>=n || r<0 || r>=m)

int gcd(int a,int b) {
	if(a%b == 0) return b;
	return gcd(b,a%b);
}
signed main() {
    IO;
    int n;
    string s1,s2;
    cin >> n;
    
    for(int i=0; i<n; i++) {
    	cin >> s1 >> s2;
    	// if(s[0] == '0' || l[0] == '0') continue;
    	int d1=0,d2=0;
    	for(int k=0; k<s1.size(); k++) {
    		if(s1[k] == '1') d1 += (1 << (s1.size()-1-k));
		}
		for(int k=0; k<s2.size(); k++) {
    		if(s2[k] == '1') d2 += (1 << (s2.size()-1-k));
		}
		
		cout << "Pair #" << i+1 << ": ";
		if(gcd(d1,d2) > 1) cout << "All you need is love!\n";
		else cout << "Love is not all you need!\n";
		
	}
    return 0;
}

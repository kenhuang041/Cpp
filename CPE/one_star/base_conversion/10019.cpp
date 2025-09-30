// https://zerojudge.tw/ShowProblem?problemid=e545

#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pci pair<char,int>
// #define int long long
#define F first
#define S second
#define N 55

string convert_2(const string &s) {
	unsigned n;
	stringstream ss(s);
	ss >> dec >> n;
	bitset<32> b(n);
	return b.to_string();
}

string convert_16(const string &s) {
	unsigned n;
	stringstream ss(s);
	ss >> hex >> n;
	bitset<32> b(n);
	return b.to_string();
}

signed main() {
    IO; 
    string s;
    int n,a=0,b=0;
    cin >> n;
    while(n--) {
    	cin >> s;
    	a=0; 
		b=0;
    	string s1 = convert_2(s);
    	string s2 = convert_16(s);
    	
    	for(int i=0; i<32; i++) {
    		if(s1[i] == '1') a++;
    		if(s2[i] == '1') b++;
		} 
		
		cout << a << " " << b << "\n";
	}
    return 0;
}

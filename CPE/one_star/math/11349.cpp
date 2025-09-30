// https://zerojudge.tw/ShowProblem?problemid=e513
// 給定矩陣 看它是否對稱
// 用巢狀for跑一遍就可以了
// *注意事項
//    1.有用getline()且後面有cin的話 一定要記得cin.ignore()
//    2.題目規定不能有負數 但測資裡面有 記得判斷負數並輸出 Non-symmetric.
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 36
#define F first 
#define S second 

signed main() {
    IO;
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++) {
    	string s;
    	getline(cin,s);
    	int k=0,ok = 1;
    	while(!isdigit(s[k])) k++;
    	
    	int num = stoll(s.substr(k));
    	int a[num][num];
    	for(int q=0; q<num; q++) {
    		for(int r=0; r<num; r++) {
    			cin >> a[q][r];
    			if(a[q][r] < 0) ok = 0;
			}
		}
		cin.ignore();
		if(!ok) {
			cout << "Test #" << i+1 << ": Non-symmetric.\n";
			continue;
		}
		
		ok = 1;
		for(int q=0; q<num; q++) {
    		for(int r=0; r<num; r++) {
    			if(a[q][r] != a[num-q-1][num-r-1]) {
    				ok = 0;
    				break;
				}
			}
		}
		
		if(ok) cout << "Test #" << i+1 << ": Symmetric.\n";
		else cout << "Test #" << i+1 << ": Non-symmetric.\n";
	}
    return 0;
}

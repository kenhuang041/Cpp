// https://zerojudge.tw/ShowProblem?problemid=c007
// 把基數的""換成``、偶數的""換成''
// for遍歷輸入 把更改好的string丟入ans一併輸出
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define N 55

signed main() {
    IO;
    int n = 0;
    string line,ans="";
    while(getline(cin,line)) {
      	for(auto ch : line) {
        		if(ch=='"') {
      				if(n%2 == 0) ans += "``";
      				else ans += "''";
      				n++; 
    			  } 
        		else ans += ch;
    		}
  		  ans += "\n";
  	}
  	
  	cout << ans;
    return 0;
}

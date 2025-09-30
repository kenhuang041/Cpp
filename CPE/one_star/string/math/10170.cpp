// https://zerojudge.tw/ShowProblem?problemid=e555
// S代表第一組旅行團人數 要求第D天的入住人數
// 假設目前S = 1,D = 6
// 依照規則 第一組人走後來的旅行團人數應為上一組人數+1 也就是2
// 依照規則 第二組會住兩天 天數來到第三天
// 第三組會住三天 此時剛好是要查至找的第六天
// 第六天的人數是第三組的三人 所以輸出3

// 用while模擬即可 C++的話不會TLE
#include <bits/stdc++.h>
using namespace std;
#define pis pair<int,string>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 10005
#define F first
#define S second

signed main() {
    IO;
    int s,d;
    while(cin >> s >> d) {
      	int t = s;
      	while(t<d) {
        		t += (s+1);
        		s++;
  		  }
  		
  		cout << s << "\n";
  	}
	
    return 0;
}

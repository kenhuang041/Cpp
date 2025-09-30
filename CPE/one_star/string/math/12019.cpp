// https://zerojudge.tw/ShowProblem?problemid=f709
// 給日期 輸出那天星期幾
// 可能要備d[]
// 算從1/1至指定日期之間的天數 % 7 即可
#include <bits/stdc++.h>
using namespace std;
#define piii pair<pair<int,int>,int>
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 100005
#define F first
#define S second

signed main() {
    IO;
    int n;
    int d[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    cin >> n;
    for(int i=0,month,day; i<n; i++) {
    	cin >> month >> day;
    	
    	int t=4;
    	for(int k=0; k<month-1; k++) t += d[k];
    	t += day;
    	
    	switch((t%7)) {
    		case 0:
    			cout << "Monday\n";
    			break;
    		case 1:
    			cout << "Tuesday\n";
    			break;
    		case 2:
    			cout << "Wednesday\n";
    			break;
    		case 3:
    			cout << "Thursday\n";
    			break;
    		case 4:
    			cout << "Friday\n";
    			break;
    		case 5:
    			cout << "Saturday\n";
    			break;
    		case 6:
    			cout << "Sunday\n";
    			break;
		}
	}
    return 0;
}

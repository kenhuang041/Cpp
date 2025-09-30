// https://zerojudge.tw/ShowProblem?problemid=d097
// 假設輸入數列是: 2 3 6 4
// 則其差值所形成的數列為: 1 3 2
// 差值數列排序後，若相鄰項目的差值皆為1，則輸出Jolly
// v存差值數列，sv存1,2...n-1，相當於符合條件的差值數列
// 判斷是否相同即可
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 1005 

signed main() { 
	IO;
	int n,prev,tmp;
	while(cin >> n) {
		vector<int> v,sv;
		cin >> prev;
		
		for(int i=1; i<n; i++) {
			cin >> tmp;
			v.push_back(abs(tmp-prev));
			sv.push_back(i);
			prev = tmp;
		}
		sort(v.begin(),v.end());
		
		if(v == sv) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
	return 0;
}

// https://zerojudge.tw/ShowProblem?problemid=c045
// 把文字順時針90度翻轉然後輸出 
// 取字數最大的 然後依序輸出
// *要特別注意的是輸出格式 
//     1.沒有東西要輸出" "
//     2.最後一行的最後一格不能輸出" "
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
    int mx = -1,idx=0,i=0;
    string s;
    vector<string> v;
    while(getline(cin,s)) {
    	int sz = s.size();
    	if(sz > mx) {
    		mx = sz;
    		idx = i;
		}
    	v.push_back(s);
    	i++;
	} 
	
	for(int i=0; i<v[idx].size(); i++) {
		for(int j=v.size()-1; j>=0; j--) {
			if(i >= v[j].size()) {
				if(i == v[idx].size()-1 && j == 0) {}
				else cout << " ";
				continue;
			}
			cout << v[j][i];
		}
		cout << "\n";
	}
    return 0;
}

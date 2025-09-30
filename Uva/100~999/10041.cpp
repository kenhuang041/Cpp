// https://zerojudge.tw/ShowProblem?problemid=a737
// 排序取中位數
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
    for(int i=0; i<n; i++) {
    	int p;
    	vector<int> v;
    	cin >> p;
    	for(int j=0,tmp; j<p; j++) {
    		cin >> tmp;
    		v.push_back(tmp);
		}
		
    	sort(v.begin(),v.end());
    	int mid = v[v.size() / 2];
    	
    	int t=0;
    	for(auto it : v) {
    		if(it != mid) t += abs(it-mid);
		}
		
		cout << t << "\n";
	}
    return 0;
}

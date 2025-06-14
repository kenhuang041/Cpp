//重組問題
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
vector<int> v;
int mx = -1;
bool ok = 0;

void dfs(multiset<int> mst) {
	if(mst.empty()) { //mst沒有差值 可以輸出答案了 
        sort(v.begin(), v.end());
        for (auto i : v) cout << i << " "; //輸出最小字典序陣列
        cout << endl;
        for (int i = v.size() - 1; i >= 0; i--) cout << mx - v[i] << " "; //反推最大字典序陣列 
        cout << endl;
        exit(0);
	}
	
	multiset<int> st = mst; //複製st 
	int maxdiff = *prev(st.end()); //取st內最大差值 
	int x = mx - maxdiff; //嘗試放入左側 (取v[n-1] - 目前最大差值)  
	ok = 1;
	
	//假設x在答案(v[])內，則 x 跟 v[] 所有項目的差值應該存在於st 
	for(auto i : v) {  //取得x和v所有項的差值 
		int y = abs(x-i);  
		auto it = st.find(y); //差值是否存在於st 
        if (it != st.end()) {
        	st.erase(it); 
		}
		else {ok = 0; break;} //若有一項不存在則不放入 x 
	}
	if(ok) {
		v.push_back(x); //放入x 
		dfs(st); //繼續遞迴 
		v.pop_back(); //推出x 因為後面要接著判斷放入右側 
	}
	//___________________ 
	st = mst;
	x = v[0] + maxdiff; //嘗試放入右側 (取v[0] + 目前最大差值)
	ok = 1;
	   
	for(auto i : v) { //跟放入左側差不多的處理 
		int y = abs(x-i);
		auto it = st.find(y);
        if (it != st.end()) {
        	st.erase(it); 
		}
		else {ok = 0; break;}
	}
	if(ok) {
		v.push_back(x);
		dfs(st);
		v.pop_back();
	}
}

signed main() {
	int n,tmp;
	multiset<int> st;
	cin >> n;
	if(n==1) { //特判規避 n=1 
		cout << "0\n0";
		exit(0);
	} 
	
	for(int i=0; i<(n*(n-1))/2; i++) {
		cin >> tmp;
		st.insert(tmp);
	}
	mx = *prev(st.end());
	v.push_back(0);  
	v.push_back(mx); 
	//初始化v = {0,mx} 
	st.erase(st.find(mx)); //mx已放入v 則st刪除mx 
	dfs(st); //開始遞迴 
	return 0;
}

// 2024/06 缺字問題
#include<bits/stdc++.h> 
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
string s,fs;
unordered_set<string> st;
int n;

void dfs(string ns,int now) {
    if(ns.size() >= n) {
        if(st.count(ns) <= 0) { 
		    // string的find 最壞 O(s.size() * fs.size()) 
		    // set的find/count 最壞O(logN) -> N是set大小 
		    // unordered_set 只要O(1)
		    cout << ns;
		    exit(0);
		}
    }
    else {
		for(int i=0; i<s.size(); i++) {
		    dfs(ns+s[i],++now);
		} 
    }
}

signed main() {
    IO; 
    cin >> s >> n >> fs;
    for(int i=0; i<=fs.size()-n; i++) st.insert(fs.substr(i,n));
    dfs("",0);
    return 0;
}

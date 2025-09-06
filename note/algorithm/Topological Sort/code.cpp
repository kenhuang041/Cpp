// 拓樸排序
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define int long long
#define N 1005
vector<int> v[N],ans;
int in[N]; // 指向 節點u 的邊一共 in[u]條 
int n;

void bfs() {
	queue<int> q;
	for(int i=0; i<n; i++) {
		if(in[i] == 0) q.push(i);
	}
	
	while(q.size()) {
		int curr = q.front();
		q.pop();
		ans.push_back(curr);
		
		for(auto nxt : v[curr]) {
			in[nxt]--;
			if(in[nxt] == 0) q.push(nxt);
		}
	}
}

signed main() {
	IO;
	memset(in,0,sizeof(in));
	cin >> n;
	for(int i=0,a,b; i<n-1; i++) {
		cin >> a >> b;
		
		v[a].push_back(b);
		in[b]++;
	}
	
	bfs();
	for(auto it : ans) cout << it << " ";
	return 0;
}

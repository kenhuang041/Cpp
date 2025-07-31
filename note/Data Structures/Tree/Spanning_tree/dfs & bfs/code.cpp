#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 1005
vector<int> tree[N],spanning_tree[N];
int visited[N];

void dfs(int u) {
	visited[u] = 1;
	for(auto v : tree[u]) {
		if(!visited[v]) {
			spanning_tree[u].push_back(v);
			spanning_tree[v].push_back(u);
			dfs(v);
		}
	}
}

void bfs() {
	memset(visited,0,sizeof(visited));
	for(int i=0; i<10; i++) spanning_tree[i].clear();
	
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	while(q.size() > 0) {
		int u = q.front();
		q.pop();    
		
		for(auto v : tree[u]) {
			if(!visited[v]) {
				visited[v] = 1;
				q.push(v);
				spanning_tree[u].push_back(v);
				spanning_tree[v].push_back(u);
			}
		}
	}
}

void print_tree() {
	for(int i=0; i<10; i++) {
		cout << i << ": ";
		for(auto it : spanning_tree[i]) {
			cout << it << " ";
		}
		cout << "\n";
	}
}
signed main() {
	IO;
	memset(visited,0,sizeof(visited));
	int a,b;
	while(cin >> a >> b) {
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	// 暫時限制節點數 < 10
	// 可調整 
	dfs(0);
	print_tree();
	
	bfs();
	print_tree();
    return 0;
}

/*
0 1 
0 2 
1 3 
3 4 
4 5 
5 1 
5 2 
2 6 
*/ 

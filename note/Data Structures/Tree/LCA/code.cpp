#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 100005
#define LOG 20
vector<int> tree[N];
int up[N][LOG];
int depth[N];

void dfs(int u,int p) {
    up[u][0] = p;
    for(int i=1; i<LOG; i++) {
	up[u][i] = up[up[u][i-1]][i-1];
    }	
    for(auto v : tree[u]) {
	if(v != p) {
	    depth[v] = depth[u]+1;
	    dfs(v,u);
	}
    }
}

int query(int u,int v) {
    if(depth[u] < depth[v]) swap(u,v);
    for(int i=LOG-1; i>=0; i--) {
	if(depth[u] - (1 << i) >= depth[v]) {
	    u = up[u][i];
	}
    }
	
    if(u == v) return u;
	
    for(int i=LOG-1; i>=0; i--) {
	if(up[u][i] != up[v][i]) {
	    u = up[u][i];
	    v = up[v][i];
	}
    } 
	
    return up[u][0]; //!
}

signed main() {
    IO;
    int n,u,v;
    cin >> n;
    
    for(int i=0,a,b; i<n-1; i++){
    	cin >> a >> b;
    	tree[a].push_back(b);
    	tree[b].push_back(a);
    }
	
    dfs(0,-1);
    cin >> u >> v;
    cout << query(u,v);
    return 0;
} 

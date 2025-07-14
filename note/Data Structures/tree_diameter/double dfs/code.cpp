// apcs 2016/03 血緣關係
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 100005
vector<int> tree[N];
int mx = -1,mx_node;

void dfs(int u,int parent,int t) {
    for(auto v : tree[u]) {
	if(v == parent) continue;
	dfs(v,u,t+1);
    }	
    if(t > mx) {
	mx_node = u;
	mx = t;
    }
}

signed main() {
    IO;
    int n;
    cin >> n;
	
    for(int i=0,a,b; i<n-1; i++) {
	cin >> a >> b;
	tree[a].push_back(b);
	tree[b].push_back(a);
    }
	
    dfs(0,-1,0);
    dfs(mx_node,-1,0);
    cout << mx;
    return 0;
} 

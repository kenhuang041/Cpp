#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 100005
vector<int> tree[N];
int cost[N];
int n;

int dfs(int u,int parent) {
    int t = 1,r = 0;
    for(auto i : tree[u]) {
	if(i == parent) continue;
	r = dfs(i,u);
	t += r;
	cost[u] = max(cost[u],r);
    }
	
    cost[u] = max(cost[u],n-t);
    return t;
}

signed main() {
    IO;
    cin >> n;
    for(int i=0,a,b; i<n-1; i++) {
	cin >> a >> b;
	tree[a].push_back(b);
	tree[b].push_back(a);
    }
	
    dfs(0,-1);
    int mn = INT_MAX,ans = -1;
    for(int i=0; i<n; i++) {
	if(cost[i] < mn) {
	    mn = cost[i];
	    ans = i;
	}
    }
	
    cout << ans;
    return 0;
} 

/*
5
1 2
2 3
1 0
1 4
*/

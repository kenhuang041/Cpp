// apcs 2016/03 血緣關係
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define N 100005
#define F first
#define S second
vector<int> tree[N];
int dp[N];
int ans=0;

void dfs(int u,int parent) {
    int max1 = 0,max2 = 0;
	
    for(auto v : tree[u]) {
	if(v == parent) continue;
	dfs(v,u);
		
	int d = dp[v]+1; //節點u到節點v的距離記得算 所以要+1 
	if(d > max1) {
	    max2 = max1;
	    max1 = d;
	} 
	else if(d > max2) {
    	    max2 = d;
	}
    }
	
    dp[u] = max1;
    ans = max(ans,max1+max2);
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
	
    dfs(0,-1);
    cout << ans;
    return 0;
} 

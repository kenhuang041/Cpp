#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int> 
#define F first
#define S second 
#define int long long
#define N 1005
vector<pii> G[N];
int dist[N]; //節點 距離 

auto cmp = [](pii a,pii b) {
	return a.S > b.S;
};
 
void dijkstra(int start) {
	memset(dist,0x3F,sizeof(dist));
	priority_queue<pii,vector<pii>,decltype(cmp)> pq(cmp);
	dist[start] = 0;
	pq.push({start,0});
	
	while(pq.size() > 0) {
		pii u = pq.top();
		pq.pop();
		
		if(dist[u.F] < u.S) continue;
		cout << u.F << endl;
		for(auto v : G[u.F]) {
			//cout << dist[u.F] + v.S << " " << dist[v.F] << " | ";
			if(dist[u.F] + v.S < dist[v.F]) {
				dist[v.F] = dist[u.F] + v.S;
				pq.push({v.F,dist[v.F]});
			}
		}
	}
}
signed main() {
	IO;
	int n,a,b,w;
	while(cin >> a >> b >> w) {
		G[a].push_back({b,w});
		G[b].push_back({a,w});
	}
	
	dijkstra(1);
	cout << dist[6]; //查詢 節點1 到 節點6 的最短路徑 
	return 0;
}

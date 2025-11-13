// 2025/06/17 貪心闖關 
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define F first
#define S second
#define ID curr.S
#define int long long

signed main() {
    IO;
    int n,t,ans = 0,now;
    cin >> n >> t;
    priority_queue<pii,vector<pii>, greater<pii> > pq;
    vector<int> v(n+5),pre(n+5),nxt(n+5);
	
    for(int i=0; i<n; i++) {
		cin >> v[i];
		pq.push({v[i],i});
    }
    for(int i=1; i<=n; i++) { // 鏈結左右子點 
		pre[i] = i-1;
		nxt[i-1] = i;
    }
	
    now = n;
    while(!pq.empty()) {
        pii curr = pq.top();
        pq.pop();
			
        if(curr.F > t) break;
        if(curr.F != v[ID]) continue;
			
        ans += v[ID];
        v[nxt[ID]] += v[ID];
        v[ID] = 0;
        nxt[pre[ID]] = nxt[ID];
        pre[nxt[ID]] = pre[ID];
			
        if(nxt[ID] != n) pq.push({v[nxt[ID]],nxt[ID]});
    }
	
    cout << ans;
    return 0;
}

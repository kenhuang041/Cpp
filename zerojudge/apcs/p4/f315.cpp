// 2020/10 低地距離
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define N 200005
#define F first
#define S second
#define lc 2*node+1
#define rc 2*node+2

vector<pii> v;
int a[N],tree[4*N],n,ans = 0;

void build(int l,int r,int node) {
	if(l == r) {
		tree[node] = a[l];
		return;
	}
	
	int mid = (l+r)/2;
	build(l,mid,lc);
	build(mid+1,r,rc);
	tree[node] = tree[lc] + tree[rc];
}

int query(int l,int r,int ql,int qr,int node) { //查詢區間不變 
	if(ql > r || qr < l) return 0;
	if(ql <= l && r <= qr) return tree[node];  

	int mid = (l+r)/2;
	return query(l, mid, ql, qr, lc) + query(mid + 1, r, ql, qr, rc);
}

void modify(int l,int r,int node,pii val) {
	if(l == r) {
		tree[node] = val.F;
		return;
	}
	
	int mid = (l+r) / 2;
	if(val.S <= mid) modify(l,mid,lc,val);
	else modify(mid+1,r,rc,val);
	
	tree[node] = tree[lc] + tree[rc];
}

signed main() {
	cin >> n;
	memset(a,0,sizeof(a));
	for(int i = 0; i < 2*n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back({tmp, i});
    }
    sort(v.begin(), v.end());
    build(0, 2*n-1, 0);
	
	for(int i=0; i<v.size(); i+=2) {
		int l = v[i].S,r = v[i+1].S;
		if(l > r) swap(l, r);
		
		if(l + 1 <= r - 1) {
            int count = query(0, 2*n-1, l+1, r-1, 0);
            ans += count;
        }
		
		modify(0,2*n-1,0,{1,l});
		modify(0,2*n-1,0,{1,r});	
	}
	
	cout << ans;
    return 0;
}

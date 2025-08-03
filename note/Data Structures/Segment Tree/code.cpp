#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 10005
#define lc node*2+1
#define rc node*2+2
int tree[4*N],a[N];

void build(int node,int l,int r) {
    if(l == r) {
	tree[node] = a[l];
	return;
    }
	
    int mid = (l+r) / 2;
    build(lc,l,mid);
    build(rc,mid+1,r);
    tree[node] = tree[lc] + tree[rc];
}

int query(int node,int l,int r,int ql,int qr) { //ql,qr為查詢區間，不需變化 
    if(l > qr || r < ql) return 0;
    if(l >= ql && r <= qr) return tree[node];
	
    int mid = (l+r) / 2;
    return query(lc,l,mid,ql,qr) + 
	   query(rc,mid+1,r,ql,qr);
}

void modify(int node,int l,int r,int pos,int val) {
    if(l == r) {
	tree[node] = val;
	return;
    }
	
    int mid = (l+r) / 2;
    if(pos <= mid) modify(lc,l,mid,pos,val);
    else modify(rc,mid+1,r,pos,val);
    tree[node] = tree[lc] + tree[rc];
}

signed main() {
    IO;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    build(0, 0, n - 1);

    // 求 [1, 3] 區間和 
    cout << query(0, 0, n - 1, 1, 3) << '\n';

    // 修改節點: a[2] = 10
    modify(0, 0, n - 1, 2, 10);
    cout << query(0, 0, n - 1, 1, 3) << '\n';
}

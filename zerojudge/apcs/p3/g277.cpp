// 2021/09 幸運數字
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define N 300005
#define F first
#define S second
#define lt node*2+1
#define rt node*2+2
vector<pii> v;
pii tree[4*N]; 
// 總節點數公式 (假設n是2的次方) = 2n-1 
// 如果不是的話 會超過 2N
// 所以保險起見 開 4N 
int dp[N];

// 線段樹 存當前區間最小值跟最小值的位置 
// 查找時間更快  
void build(int l,int r,int node) {
    if(l == r) { //葉節點 
        tree[node] = v[l];
	return;
    }
	
    int mid = (l+r)/2;
    build(l,mid,lt);
    build(mid+1,r,rt);
	
    //判斷左右子樹哪個比較小 選小的 
    if(tree[lt].F > tree[rt].F) tree[node] = tree[rt];
    else tree[node] = tree[lt];
}

pii query(int l,int r,int ql, int qr,int node) { //ql,qr是查找區間 
    if(qr < l || ql > r) return {INT_MAX,-1};
    if(l >= ql && r <= qr) return tree[node];
	
    int mid = (l+r)/2;
    pii nl = query(l,mid,ql,qr,lt);
    pii nr = query(mid+1,r,ql,qr,rt);
    //一樣是看哪個比較小就選哪個 
    if(nl.F > nr.F) return nr;
    else return nl;	
}

signed main() {
    IO;
    int n;
    cin >> n;
    for(int i=0,tmp; i<n; i++) {
	cin >> tmp;
	v.push_back({tmp,i});
	dp[i] = (i-1 >= 0 ? dp[i-1] : 0) + tmp;
    }
	
    build(0,n-1,0);
    int l = 0, r = n-1;
    while(l < r) {
	int mid = query(0,n-1,l,r,0).S;
		
	if(l+1 == r) { //多這個條件可以少一次query 省時間 
	    if(v[l] < v[r]) l = r;
	    break;
	} 
	else if(mid == l) l = mid+1; //沒有左邊 直接跳過 向右側區間走
	else if(mid == r) r = mid-1; //沒有右邊 直接跳過 向左側區間走 
	else { //往較小區間走 
	    int left = dp[mid] - dp[l] + v[l].F; //只有 dp[mid] - dp[l] 的話會多減一個 v[l].F，得補回來 
	    int right = dp[r] - dp[mid] + v[mid].F; //跟上述同理 
			
	    if(left > right) r = mid-1;
	    else l = mid+1;	
	}
    }
		
		
    cout << v[l].F << endl;
    return 0;
} 

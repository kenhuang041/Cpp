// h029 貨物分配
// dp[u]存節點u總和，v[u]存節點u連通的節點
// 先用 build() 建構 dp[]
// 每次dfs找到儲存位置後 再利用收束更新dp[]
// 原本以為會TLE 結果直接過了 :)

#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second
#define A (v[u][0])
#define B (v[u][1])
#define N 200005

int n,m;
vector<int> v[N],dp(N,-1),ans;

void build(int u) {
    if(v[u].size() == 1) return;
    build(A);
    build(B);
    dp[u] = dp[A] + dp[B];
}

void dfs(int u, int t) {
    if(v[u].size() == 1) {
        A += t;
        dp[u] += t;
        ans.push_back(u);
        return;
    }

    if(dp[A] > dp[B]) dfs(B,t);
    else dfs(A,t);

    dp[u] = dp[A] + dp[B];
}

signed main() {
    IO;
    cin >> n >> m;
    vector<int> push(m);
    for(int i=n,tmp; i<=2*n-1; i++) {
        cin >> tmp;
        v[i].push_back(tmp);
        dp[i] = tmp;
    }
    for(int i=0; i<m; i++) cin >> push[i];
    for(int i=0,p,s,t; i<n-1; i++) {
        cin >> p >> s >> t;
        v[p].push_back(s);
        v[p].push_back(t);
    }

    build(1);
    for(auto it : push) dfs(1,it);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
        if(i != ans.size()-1) cout << " ";
    }
    return 0;
}

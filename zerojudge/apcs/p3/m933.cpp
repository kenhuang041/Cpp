// m933 邏輯電路
// dfs+dp解 要不然會TLE
// dp存已經執行過的Gate的結果 有的話就直接用 沒有的話就繼續dfs
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second
#define N 52005 //p+q+r
#define A (pv[cur][0])
#define B (pv[cur][1])
#define OUT (ny<0 || ny>=n || nx<0 || nx>=m)

int p,q,r,m,mx=-1;
vector<int> pv[N],v(N);
vector<pii> dp(N,{-1,0});

void dfs(int cur) {
    // if(cur <= p) return v[cur];
    if(dp[cur].F != -1) return;
    else if(cur >= p+q+1) {
        dfs(A);
        dp[cur] = dp[A];
    }

    int a,b;
    if(v[cur] == 1) { // AND
        dfs(A); dfs(B);
        dp[cur] = {(dp[A].F & dp[B].F), (max(dp[A].S,dp[B].S) + 1)};
    }
    else if(v[cur] == 2) { // OR
        dfs(A); dfs(B);
        dp[cur] = {(dp[A].F | dp[B].F), (max(dp[A].S,dp[B].S) + 1)};
    }
    else if(v[cur] == 3) { // XOR
        dfs(A); dfs(B);
        dp[cur] = {(dp[A].F ^ dp[B].F), (max(dp[A].S,dp[B].S) + 1)};
    }
    else if(v[cur] == 4) { // NOT
        dfs(A);
        dp[cur] = {(!dp[A].F), (dp[A].S + 1)};
    }
}

signed main() {
    IO; 
    cin >> p >> q >> r >> m;
    for(int i=1; i<=p+q; i++) {
        cin >> v[i];
        if(i <= p) dp[i] = {v[i],0};
    }
    for(int i=0,a,b; i<m; i++) {
        cin >> a >> b;
        pv[b].push_back(a);
    }

    vector<int> ans;
    for(int i=p+q+1; i<=p+q+r; i++) {
        dfs(i);
        mx = max(mx,dp[i].S);
        ans.push_back(dp[i].F);
    }

    cout << mx << "\n";
    for(auto it : ans) cout << it << " ";
    return 0;
}

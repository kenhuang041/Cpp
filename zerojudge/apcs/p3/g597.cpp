// g597 生產線
// 重複最多的格子用最少的t 其次是w[i]較高者
// 用 前綴和+差分 求得每格的單位資料
// t由小到大排序 dp由大到小排序
// 把每格 t[i] * dp[i] 加起來就會刺解答了

#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define piii pair<pair<int,int>,int>
#define int long long
#define F first
#define S second

signed main() {
    IO;
    int n,m,ans=0;
    cin >> n >> m;
    vector<piii> step(m);
    vector<int> t(n),v(n,0),dp(n);

    for(int i=0; i<m; i++) {
        cin >> step[i].F.F >> step[i].F.S >> step[i].S;
        v[step[i].F.F-1] += step[i].S; // 1-based => 0-based
        v[step[i].F.S] -= step[i].S;
    }
    for(int i=0; i<n; i++) {
        cin >> t[i];
        if(i >= 1) dp[i] = dp[i-1] + v[i];
        else dp[i] = v[i];
    }

    sort(dp.begin(), dp.end(), greater<int>());
    sort(t.begin(), t.end());

    for(int i=0; i<n; i++) ans += (t[i] * dp[i]);
    cout << ans;
    return 0;
}

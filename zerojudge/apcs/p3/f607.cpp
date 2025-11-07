// f607 切割費用
// 用 priority_queue 自動排序輸入，再用set存數線位置 (初始是 0 跟 L)
// 用 lower_bound 找到被切割棍子的最大值 再用 prev(it) 推出最小值
// 最大值 - 最小值就會是切割費用了
// 記得把切割位置加入到 set
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second

signed main() {
    IO;
    int n,l,ans = 0;
    cin >> n >> l;
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    set<int> st;
    st.insert(0);
    st.insert(l);

    for(int i=0,a,b; i<n; i++) {
        cin >> a >> b;
        pq.push({b,a});
    }

    while(!pq.empty()) {
        int cur = pq.top().S;
        pq.pop();
        
        auto it = st.lower_bound(cur);
        if(it == st.end()) it = prev(it);
        
        ans += (*it - *prev(it));
        st.insert(cur);
    }

    cout << ans;
    return 0;
}

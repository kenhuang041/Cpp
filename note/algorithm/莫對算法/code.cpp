// https://cses.fi/problemset/task/1734
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second
#define lc node*2+1
#define rc node*2+2
#define N 200005
#define endl "\n"
int n, m, ans=0;
int cnt[N];
int block_size; // k

struct Query { 
    int l,r,idx; // 左界, 右界, 原始索引
    bool operator<(const Query& other) const { // 複寫排序規則
        int b1 = l / block_size; // 左界的區塊編號
        int b2 = other.l / block_size; // 另一個查詢項的左界區塊編號
        
        if(b1 != b2) return b1 < b2; // 由小到大排序
        // 同一區塊內，根據右界排序，偶數區塊由小到大，奇數區塊由大到小
        // 可以減少指針移動距離，提升效率
        else return (b1 & 1) ? (r < other.r) : (r > other.r);
    }
};

void add(int x) { // 加入元素 
    if(cnt[x] == 0) ans++; // 之前沒出現過 新增至答案
    cnt[x]++; // 出現次數++
}

void remove(int x) { // 刪除元素
    cnt[x]--; // 出現次數--
    if(cnt[x] == 0) ans--; // 如果刪除後沒出現了 從答案扣除
}

signed main() {
    IO;
    cin >> n >> m;
    block_size = sqrt(n); // 區塊大小
    vector<int> v(n);
    vector<int> temp;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        temp.push_back(v[i]);
    }

    sort(temp.begin(), temp.end()); 
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    for(int i=0; i<n; i++) {
        v[i] = lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin() + 1;
    }

    vector<Query> queries(m); // 儲存查詢項
    for(int i=0; i<m; i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; queries[i].r--; //0_based
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end()); // 排序

    int curL = 0, curR = -1; // 當前區間 [curL, curR]
    vector<int> res(m); // 儲存每個查詢的結果
    for(auto& q : queries) { // 處理每個查詢
        while(curL > q.l) add(v[--curL]); // 擴展左界
        while(curR < q.r) add(v[++curR]); // 擴展右界
        while(curL < q.l) remove(v[curL++]); // 收縮左界
        while(curR > q.r) remove(v[curR--]); // 收縮右界
        res[q.idx] = ans;
    }

    for(int i=0; i<m; i++) 
        cout << res[i] << endl;
    return 0;
}

/*
莫對算法:
一次性讀取所有查詢區間，並進行左右區間的排序

排序後再依次處裡每個查詢，透過不斷移動左右指針來取得答案
複雜度就是移動指針的次數，平均每個查詢 O(√n)，總體 O((n+m)√n)?
*/

/*
莫隊演算法 (Mo's Algorithm) 總結：
1. 性質：離線演算法 (Offline Algorithm)。必須先知道所有詢問才能排序處理。
2. 核心：透過分塊排序，最小化 L 與 R 指標移動的曼哈頓距離。
3. 複雜度分析：
   - 指標 L：每個查詢移動距離不超過 √n，共 m 次查詢 -> O(m√n)
   - 指標 R：每個分塊內單調移動 (0->n)，共有 √n 個塊 -> O(n√n)
   - 總複雜度：O((n + m)√n)。
4. 適用場景：區間查詢問題，且 add / remove 操作可以在 O(1) 或 O(log n) 完成。
*/


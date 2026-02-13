# 莫對算法
屬於離線演算法 (必須知道所有詢問才能進行排序處理)
> 用來處理「不需修改內容的靜態區間統計」的題型

假設有陣列 $[1, 2, 3, 2, 1, 3, 2, 1]$ <br>
我們要查詢三個區間 $Q_1[1, 3],  Q_2[5, 8],  Q_3[2, 6]$ <br>


---
### 分塊 
先將整個陣列分為多個區塊
- 若單塊大小為k，則一共會有 n/k 個區塊 (n 為陣列大小)
- v[i] 位於第 i/k 個區塊 (區塊編號由0開始)
- k 通常為 √n

> ex. $[1, 2, 3, 2, 1, 3, 2, 1]$ 會被分為 $[1, 2, 3]$, $[2, 1, 3]$, $[2, 1]$ 三個區塊

<br>

### 排序
一次性讀取所有查詢區間 $[l,r]$ 後，依照下列規則進行排序
- 先讀取兩個查詢的左界屬於哪個區塊
- 左界由小到大進行排序
- 若左界相同，則排序右界
  - 偶數區間由小到大
  - 基數區間由大到小

``` cpp=
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
```

<br>

### 指標移動
排序完成後，接著定義指標向前/後移動的處理
```
int n, m, ans=0;
int cnt[N];
int block_size; // k

void add(int x) { // 加入元素 
    if(cnt[x] == 0) ans++; // 之前沒出現過 新增至答案
    cnt[x]++; // 出現次數++
}

void remove(int x) { // 刪除元素
    cnt[x]--; // 出現次數--
    if(cnt[x] == 0) ans--; // 如果刪除後沒出現了 從答案扣除
}

void solve() {
    int curL = 0, curR = -1; // 當前區間 [curL, curR]
    vector<int> res(m); // 儲存每個查詢的結果

    for(auto& q : queries) { // 處理每個查詢
        while(curL > q.l) add(v[--curL]); // 向左擴展
        while(curR < q.r) add(v[++curR]); // 向右擴展
        while(curL < q.l) remove(v[curL++]); // 向左收縮
        while(curR > q.r) remove(v[curR--]); // 向右收縮
        res[q.idx] = ans;
    }
}
```

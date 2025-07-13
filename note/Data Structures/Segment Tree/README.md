# 線段樹
求區間和跟修改都優於普通陣列的資料結構 <br>
複雜度跟BIT一樣，都是O(log n) <br>
但更直觀一點? (我是這麼覺得^^) <br>

### 結構
線段樹是一個完整二元樹，假設是一個長度為9的線段樹，則其二元樹如圖
()

用陣列存取，若根節點為`a[0]`，則其左右子節點存放位置如下

$$
\begin{aligned}
左子節點 &\rightarrow &2i \\
右子節點 &\rightarrow &2i+1 \\
\end{aligned}
$$

依照規則填入數字，所以`a[1] = [5,8]`, `a[2] = [0,4]` <b4>
接下來就可以用程式碼實現了 
``` cpp
// 建線段樹
void build(int node,int l, int r) {
    if (l == r) { // 葉節點 終止遞迴
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;                            // 切分
    build(node * 2, l, mid);                          // 左子樹 → node*2
    build(node * 2 + 1, mid + 1, r);                  // 右子樹 → node*2+1
    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 設定當前節點值為兩子節點總和
}
```

### 功能
查詢區間和方法如下
- 從根節點開始向下找，若當前節點 `l > find_l, find_r < r`，則代表此節點被包含在查詢區間內
- 直到找到區間內只有一個數字的葉節點，即可得知查詢區間和
- 如果節點在範圍外，可以直接終止遞迴

```cpp
// 計算 a[l] ~ a[r] 的總和
int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;             // 節點在範圍外
    if (ql <= l && r <= qr) return tree[node];  // 完全包含，回傳節點值

    int mid = (l + r) / 2;                          // 切分
    return query(node * 2, l, mid, ql, qr) +        // 左子樹
           query(node * 2 + 1, mid + 1, r, ql, qr); // 右子樹
}
```
修改單點也是差不多的方式，從根節點向下找到需更改的葉節點，再透過遞迴的收束更改被影響的節點就好了
```cpp
// 單點修改 a[pos] = val;
void modify(int node, int l, int r, int pos, int val) {
    if (l == r) { //修改葉節點
        tree[node] = val;
        return;
    }

    //二分搜尋
    int mid = (l + r) / 2;
    if (pos <= mid)
        modify(node * 2, l, mid, pos, val);
    else
        modify(node * 2 + 1, mid + 1, r, pos, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1]; //更改被影響節點
}

```



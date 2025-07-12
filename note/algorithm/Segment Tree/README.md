# 線段樹
求區間和跟修改都優於普通陣列的資料結構 <br>
複雜度跟BIT一樣，都是O(log n) <br>
但更直觀一點? (我是這麼覺得^^) <br>

<結構>
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
void build(int l, int r,int node) {
    if (l == r) { // 葉節點 終止遞迴
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2; // 當前節點分兩半
    build(node * 2, l, mid);        // 左子樹 → node*2
    build(node * 2 + 1, mid + 1, r); // 右子樹 → node*2+1
    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 設定當前節點值為兩子節點總和
}
```

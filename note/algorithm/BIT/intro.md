# 樹狀數組
全名 Binary Index Tree  
看下面這個表就知道了

| 資料結構  | 查詢區間和         | 修改單點  |
| -------- | ----------------- | -------- |
| 陣列      |   O(n)           | O(1)     |
| 前綴和    |   O(1)           | O(n)     |
| BIT      |   O(log n)        | O(log n) |

查找跟修改的複雜度，BIT明顯優於於普通陣列及前綴和 <br>
想快速查找區間和 + 快速修改的話，BIT是個不錯的選擇

### 原理
若將一個1~8的資料存入BIT，則其結構如下圖
()

用陣列實現的話，結構如圖所示
()

問題來了，應該怎樣將指定數加到對應格?
答案是用lowbit(n)
lowbit(n) 是將n轉二進制，取由右邊往前數到的第一個1的值 <br>

$$
\begin{aligned}
3_{(10)}  &\rightarrow  &011_{(2)},\  &\mathit{lowbit} = 1 \\
12_{(10)} &\rightarrow  &1100_{(2)},\ &\mathit{lowbit} = 4
\end{aligned}
$$

程式碼<br>
``` cpp
int lowbit(int x) {return x & -x;}
/*
lowbit(3)
3 -> 011
-3 -> 101
( 二進制負數 = 補數+1 )

011 & 101 = 001
=> 1
*/
```

回到問題，要怎樣使用 lowbit(n) 才能達到理想的效果? <br>
答案是通靈(? <br>
反正就是讓 x 一直 += lowbit(x)，藉此經過每個須存放x的節點
``` cpp
void build(int n) {
  for (int i = 1; i <= n; i++)  //遍歷需存放的項目: 1~n
    for (int x = i; x < 200005; x += lowbit(x)) //遍歷需存放的節點
        bt[x] += a[i]; //存入BIT
}
```

### 功能
查詢區間和及修改的複雜度最優的BIT，該如何實現這些功能? <br>
搜尋 1\~x 區間和的話，可以讓 x -= lowbit(n) 直到變成0，藉此經過所有需要的區間 <br>
以1~7為例:

$$
\begin{aligned}
7(000111)  &\rightarrow  6(000110) &\rightarrow  4(000100) &\rightarrow  0(000000)
\end{aligned}
$$

可以上去看圖，是不是就經過所有節點了^^
``` cpp
//搜尋 1~x 區間和
int find(int x) {
  int sum=0;
  for(int i=x; i>0; i-=lowbit(i))
    sum+=bt[i];
  return sum;
}

//計算 l~r 的區間和 (包含l及r 所以要l-1)
int query(int l,int r) {
  return find(r) - find(l-1)l
}
```

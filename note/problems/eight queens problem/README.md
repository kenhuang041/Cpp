# 八皇后問題
### 題目敘述
一個很經典的問題，如何在8x8的西洋棋盤中放個皇后 <br>
若放置位置的行、列、正對角線或反對角線上有其他皇后，她們兩個就會打起來 <br>
則要怎樣才能在棋盤中放滿八個皇后?

<br>

### 思路
這其實是一個dfs的題目，也就是放置皇后並遞迴接著放，不合就退回去繼續找　<br>
從第一行開始遞迴 (row=0)，row=8時終止，這樣能錯開行數，不會撞到一起 <br>
可以開三個陣列 col[8], rc[8], cr[8]，分別代表圖中各個狀態 <br>

<br>
(圖片) <br>
<br>

接著開始遞迴 <br>
每次都遍歷當前行的每個列，並判斷此列、正對角線及反對角線有沒有放過皇后 <br>
都沒有的話就放置，並更新陣列，然後繼續遞迴 <br>
回來以後記得把陣列復原就可以了 <br>

``` cpp
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second
#define N 10
int col[N], rc[N*2], cr[N*2]; // 正對角線跟負對角線有15條 所以要用N*2
int put[N][N];
int n = 8, t=0;

// row - cl 的範圍是 -7~7，所以要+7避免負數
// row + cl 就不用+7了，因為範圍是 0~14

void solve(int row) {
    if(row==n) {
        t++;
        return;
    }

    for(int cl=0; cl<n; cl++) {
        if(!col[cl] && !rc[row-cl+7] && !cr[row+cl]) {
            col[cl] = rc[row-cl+7] = cr[row+cl] = 1;
            solve(row+1);
            col[cl] = rc[row-cl+7] = cr[row+cl] = 0;
        }
    }
}

signed main() {
    IO;
    solve(0);
    cout << t << "\n";
    return 0;
}
```

可以執行看看，一共有92種解 :) <br>
<br>

### 題目
https://zerojudge.tw/ShowProblem?problemid=a160 <br>
https://cses.fi/problemset/task/1624

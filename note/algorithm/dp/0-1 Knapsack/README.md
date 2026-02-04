# 01背包問題
二維求最大價值: https://hackmd.io/U7WarzrATGur_DeuRPPzrA

---
### 二維陣列求最大方法數
二維陣列求最大方法數的話，狀態轉移是會變成:

$$
dp[i][j] = \underbrace{dp[i-1][j]}_{\text{不選第 } i \text{ 個}} + \underbrace{dp[i-1][j - \text{weight}[i]]}_{\text{選擇第 } i \text{ 個}}
$$

- dp[i-1][j] 代表不使用第 i 個物品，湊出 j 個空間的方法數
- dp[i-1][j-w[i]] 代表不使用第 i 個物品，湊出 j-w[i] 個空間 (直接加上第 i 個物品時，剛好湊到 j 個空間，也就是選擇的方法數)

<br>

### 一維陣列 (滑動窗口)
因為二維只會使用到 i-1 ，也就是上個陣列的內容，所以可以直接壓縮成一維，但要由大到小處理測資
> 迴圈由大到小處理，才會保留先前的資訊，並慢慢往前更新陣列內容


    int n = 3; // 物品數量
    int W = 8; // 背包容量
    vector<int> weights = {3, 4, 5};
    vector<int> values = {30, 50, 60};
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        // 倒序遍歷背包容量
        for (int j = W; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp[x]

<br>

題目
https://cses.fi/problemset/task/3314

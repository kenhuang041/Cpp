# 01背包問題
二維求最大價值: https://hackmd.io/U7WarzrATGur_DeuRPPzrA

---
二維陣列求最大方法數的話，狀態轉移是會變成:

$$
dp[i][j] = \underbrace{dp[i-1][j]}_{\text{不選第 } i \text{ 個}} + \underbrace{dp[i-1][j - \text{weight}[i]]}_{\text{選擇第 } i \text{ 個}}
$$

- dp[i-1][j] 代表不使用第 i 個物品，湊出 j 個空間的方法數
- dp[i-1][j-w[i]] 代表不使用第 i 個物品，湊出 j-w[i] 個空間 (直接加上第 i 個物品時，剛好湊到 j 個空間，也就是選擇的方法數)


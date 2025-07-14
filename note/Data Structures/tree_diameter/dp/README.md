# 樹上DP
用dp解樹直徑

### 結構 & 原理
假設樹現在找這樣 <br>
<img width="432" height="387" alt="image" src="https://github.com/user-attachments/assets/a5517272-322c-4a3d-b45d-2a8b74ccfe1d" />

<br> 

開一個 dp[] 用來存當前節點向下走的最大路徑
- 以節點1為例，則dp[1] = 2; (1 -> 3 -> 4 or 5)
- 

# LIS
假設當前有一個序列 `[10,9,2,5,3,7,101,18]`
那麼它的最長遞增子序列可能就會是 `[2,3,7,101]` ，也可能會是 `[2,3,7,18]` (有很多種)
通常會要求的是取子序列的最長長度，解析如下
**(LIS = 最長遞增子序列)**

解析
---
建立陣列arr和dp，分別儲存序列項目及當前項目的LIS(初始值為1)
- 用for(i)遍歷arr，迴圈中在用for(j)遍歷 `arr[i]` 之前的所有項目
- 若 `arr[j] < arr[i]` (遞增子序列成立)，則當前項目的LIS = **當前項目的LIS**及**較小項目的LIS+1**的最大值						
:::warning
LIS+1代表較小項目加上當前項目的LIS
取較大值是為了防止覆蓋掉原本較大的LIS(當前項目)								
:::

#### 圖解:

<img width="721" height="47" alt="image" src="https://github.com/user-attachments/assets/556f9f87-0063-4180-ae0e-2d097b2b7527" />


`arr[i] < arr[j]`，不符合遞增子序列。 (紅色對應 `i` ,藍色對應 `j` )


<img width="719" height="42" alt="image" src="https://github.com/user-attachments/assets/952f30ee-7e10-49ad-af36-0b88219c7654" />



當前 `arr[i] < arr[j]`，則 `dp[3] = max(dp[3],dp[2]+1);`，`dp[3] = 2;`

<img width="719" height="43" alt="image" src="https://github.com/user-attachments/assets/c845e6b8-e6d0-490d-9e57-8c1618c58961" />



依序推論即可得出上圖內容，遍歷陣列並取出最大LIS即可


<br>

取得LIS
---
建立vector存取LIS項目，接著for(i)遍歷序列並判斷條件
- 若 `arr[i] <= v[v.size()-1]`，則 `v[v.size()-1] = arr[i];`
- 否則將 `arr[i]`

參考
---
https://hackmd.io/@Maxlight/SyMXR9aB2

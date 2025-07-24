# 最近共同祖先 LCA
最近共同祖先 就字面上意思 不多說 <br>
假設樹長這樣

<img width="654" height="563" alt="image" src="https://github.com/user-attachments/assets/d2d101a4-f32d-4939-a9ad-8f4f0660dd71" />

則 節點3 跟 節點1 的最近公同祖先LCA(u,v) = 節點0

### 結構 & 原理
有兩種實現的方法，這邊先講Binary Lifting (二元跳躍法) <br>
什麼是Binary Lifting? <br>
我們可以開一個二維陣列，用來存取 節點u 的第2^i個祖先 <br>
> dp[u][0] => 節點u的第1個祖先 => 節點u的父節點
> dp[u][2] => 節點u的第4個祖先 <br>
> 以圖為例，dp[4][1] => 節點4的第2個祖先 => 節點0 <br>

以此類推，我們可以得到節點u的第1,2,4...2^i個祖先 <br>
那如果要找 節點u 的第3個祖先怎麼辦? <br>
**答案是用二進制**

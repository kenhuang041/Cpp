# KMP
目的是快速判斷字串s中是否包含字串t，範例如下 

$$
\
\begin{flalign*}
s &= abbadca &\\
t &= dca &
\end{flalign*}
\
$$

### 優點
如果是暴力解的話，複雜度是Ｏ(s.size() * t.size()) <br>
但KMP能把時間壓到O(s.size() + t.size()) <br>

### 架構
暴力解的話就是從i=0開始，看 t[j] 是否都相等於 s[i] ，沒有的話i++

(code)


KMP比較聰明，會先對t做預處理：
- 開一個陣列，每格代表t.substr(0,i-1)的共同前後綴長度

> [!NOTE]註
> 這篇筆記收錄在 HackMD 教學手冊當中，集所有的教學為一身，快收藏訂閱吧！

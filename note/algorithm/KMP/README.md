# KMP
目的是快速判斷字串s中是否包含字串t，範例如下 

$$ 
\begin{aligned}
s = abbadca \\
t = dca 
\end{aligned}
$$



$$
\begin{aligned}
左子節點 &\rightarrow &2i \\
右子節點 &\rightarrow &2i+1 \\
\end{aligned}
$$


### 優點
如果是暴力解的話，複雜度是Ｏ(s.size() * t.size()) <br>
但KMP能把時間壓到O(s.size() + t.size()) <br>

### 架構

先對t做預處理：
- 開一個陣列，每格代表

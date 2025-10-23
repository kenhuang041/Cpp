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

### KMP 實做
假設現在正在匹配字串s和t 

$$
\
\begin{flalign*}
s &= ababab &\\
t &= ababac &
\end{flalign*}
\
$$

匹配到最後一個字元時 b != c 導致失配，但前面都匹配成功，再回到第一個豈不是浪費時間? <br>
那麼問題來了: 我們應該從哪個位置開始比對，才不會重複到正確的內容?

### LPS / Failure Function
針對上述問題，我們可以利用「最長相等前後綴」來解決 <br>
先開一個陣列，每格的定義如下:
- LPS: 最長相等前後綴長度
- Failure Function: 最長相等前後綴字串中最後一個索引 <br>

(其實只是差在 0-based 跟 -1-based 而已)

$$
\
\begin{flalign*}
t &= ababac & \\
LPS &=  [0,0,1,2,3,0] & \\
F &=  [-1, -1,0, 1, 2, -1] & \\
\end{flalign*}
\
$$

回到之前的問題，字串s比對字串t時，因問最後一個字元 b != c 導致失配 <br>
其中匹配失敗格前面的字串 ababa 的最長相等前後綴是 aba 
分析一下上述結論:
- 使用字串 ababa 的前綴 aba 時匹配失敗 
- 前面 ababa 都匹配成功，但後面 b != c 導致失配
- 既然使用前綴的aba失配，那是不是直接跳到與前綴相同、且同樣匹配成功的後綴aba，加快程式判斷的效率
- （以前綴為起點的結果是失配，但以後綴為起點的結果還沒有試）
<!--（依照匹配結果看，直接以後綴為起點匹配也沒有問題）
- （所以直接移就對了^^）-->

string s = "abababac";
string t = "ababac";

失配表建立完成後，則可正式開始配對
- 從最前面開始比對，如果失配，則直接跳到能繼續匹配的長度
- pos = 目前已匹配成功字串的最後一個索引 (若 "abc" 匹配成功, 則 pos=2)
- 
$$
\
\begin{flalign*}
s &= abababac & \\
t &= ababac & \\
i &= 5, pos=4 & \\
s[i] &= b, t[pos+1] = c, then pos = F[pos] = 2 & \\
\end{flalign*}
\
$$

# 最長共同子序列
假設有一個陣列`[1,5,3,2,9]`，則他的子序列有可能是`[3,9]`或是`[1,5,2]`，這就是子序列的定義
以此推演，那麼最長共同子序列(Longest Increasing Subsequence，**簡稱LCS**)就是兩個陣列中相同且最長的子序列啦:D

<font color=#F7A004>**[例題]**</font>
 - 輸入兩個字串s1和s2，請輸出最長共同子序列的長度

窮舉法當然也能做出來，只不過真的太久啦，還是動態規劃好:)

### <font color=#1936C9>**<br>思路**</font>
假設s1的最後一個字元為e1，s2的最後一個字元為e2，我們把e1和e2拿出來比較
 - <font color=white>如果e1 == e2，則我們要取不包含e1和e2時LCS的長度，並+1放至格子內(可參考下方圖片)
    
 - 但若e1 != e2，則需要分別判斷包含e1時的LCS長度以及包含e2時的LCS長度中哪個的值更大，並將他放入格子內</font>

依照上方的條件，從`s1[0]`和`s2[0]`開始到最後`s1[s1.size()]`和`s2[s2.size()]`，就可以得出LCS的長度了


### <font color=#1936C9>**圖解**</font>
假設s1=`CCGA`、s2=`TGCACGAA`
先開一個縱向大小為`s2.size()+1`、橫向大小為`s1.size()+1`的二維陣列

**判斷兩個格子的內容(字母)是否相等**，C不等於T，則取兩個藍色格子中的最大值。以此類推，**?應該填入0**
![chrome_cTfE113C1a](https://hackmd.io/_uploads/rypkGx-MC.png)

**當兩個格子相等時(C == C)，則?等於藍色格子的值+1**，以此類推完成所有格子
![chrome_aVbuVdk3Il](https://hackmd.io/_uploads/H1WUVebfC.png)

完成後長這樣，其中最長共同子序列的長度也就會是4啦
![chrome_mvUYp487zc](https://hackmd.io/_uploads/H1f6rl-M0.png)

### <font color=#1936C9>**<br>程式碼**</font>
``` cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	int dp[s1.size()+1][s2.size()+1] = {0};
	
	for(int i=0; i<=s1.size(); i++){
		for(int j=0; j<=s2.size(); j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i=1; i<=s1.size(); i++){
		for(int j=1; j<=s2.size(); j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	cout << dp[s1.size()][s2.size()];
	return 0;
}

```

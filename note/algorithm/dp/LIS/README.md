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


|![image](https://hackmd.io/_uploads/r1O72xS1lg.png)|
|---|

`arr[i] < arr[j]`，不符合遞增子序列。 (紅色對應 `i` ,藍色對應 `j` )


| ![image](https://hackmd.io/_uploads/SJSisxHJgx.png) |
|---|

當前 `arr[i] < arr[j]`，則 `dp[3] = max(dp[3],dp[2]+1);`，`dp[3] = 2;`

| ![image](https://hackmd.io/_uploads/H1OpjlSyxe.png) |
|---|

依序推論即可得出上圖內容，遍歷陣列並取出最大LIS即可

程式碼
---
``` cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,mx=0;
	cin >> n;
	int a[n],dp[n];
	vector<int> ans;
	for(int i=0; i<n; i++) cin >> a[i];
	fill(dp,dp+n,1);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(a[j] < a[i]) {
				dp[i] = max(dp[j]+1,dp[i]);
			}
		}
	}
	for(int i=0; i<n; i++) mx = max(mx,dp[i]);
	cout << mx;
	return 0;
} 

/* 測資:
8
10 9 2 5 3 7 101 18
*/
```

<br>

取得LIS
---
建立vector存取LIS項目，接著for(i)遍歷序列並判斷條件
- 若 `arr[i] <= v[v.size()-1]`，則 `v[v.size()-1] = arr[i];`
- 否則將 `arr[i]`

參考
---
https://hackmd.io/@Maxlight/SyMXR9aB2

# 樹上DP
用dp解樹直徑

### 結構 & 原理
假設樹現在找這樣 <br>
<img width="432" height="387" alt="image" src="https://github.com/user-attachments/assets/a5517272-322c-4a3d-b45d-2a8b74ccfe1d" />

<br> 

開一個 dp[] 用來存當前節點向下走的最大路徑
- 以節點1為例，則dp[1] = 2; (1 -> 3 -> 4 or 5)

大致原理如下，程式碼註解會更細一點
- 隨便挑一個點作為根節點
- dfs遍歷樹
- 遞迴時，取得當前節點u及每個子節點v的最大路徑ma1跟次大路徑max2
- 則可以設定dp[u] = max1;
- 同時更新最大直徑 ans = max(ans,max1+max2);

### 程式碼
```cpp
//樹上dp求距離
vector<int> tree[N];
int dp[N];
int ans=0;

void dfs(int u,int parent) { // 當前節點,父節點
	int max1 = 0,max2 = 0; //最大 次大
	
	for(auto v : tree[u]) { // 遍歷節點u的每個子節點v
		if(v == parent) continue; // 不能往父節點走
		dfs(v,u);
		
		int d = dp[v]+1; // 節點u到節點v的距離記得算 所以要+1 
		if(d > max1) { // 更新max1
			max2 = max1; // 原先max1變成max2
			max1 = d; 
		} 
		else if(d > max2) { // max1 > d > max2 則更新max2
			max2 = d;
		}
	}
	
	dp[u] = max1; // 設置當前節點向下最大距離 也就是max1
	ans = max(ans,max1+max2); // 更新最大直徑
}
```

很剛好的是 apcs 2016/03 的第四題就是求樹的直徑 <br>
所以code.cpp就直接存那一題的答案了

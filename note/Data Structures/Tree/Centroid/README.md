# 樹重心
我學到的方法，是透過節點的滲度來求樹重心

### 結構 & 原理
定義節點u的滲度為「移除節點u後，形成的若干棵子樹中節點數量中的最大值」<br>
範例如下圖，如果把左圖的節點4移除，會形成兩棵子樹 <br>
其中子樹節點數量分別是 2 和 3 <br>
則節點4的滲度應為較大的 3 <br>

| <img width="600" height="511" alt="image" src="https://github.com/user-attachments/assets/c5f3835f-3516-450f-9795-9c676327c940" /> |  <img width="615" height="357" alt="image" src="https://github.com/user-attachments/assets/533643cf-bf8b-4f52-9810-b45f6d9a5849" /> |
|-----|-----|


實現方法如下
- 建立陣列 cost[] 儲存每個節點的滲度
- 找一個點開始做dfs
- 建立儲存當前節點子樹大小的 t，及子節點返回值 r
- 在 for 內取子樹節點最大值，並存入 cost[u]
- 還要比較節點u上方子樹最大值，也就是 總節點數nt - 下方總子節點數t

程式碼
```cpp
vector<int> tree[N];
int cost[N];
int nt;

int dfs(int u,int parent) {
	int t = 1,r = 0;
	for(auto i : tree[u]) {
		if(i == parent) continue;
		r = dfs(i,u);
		t += r;
		cost[u] = max(cost[u],r);
	}
	
	cost[u] = max(cost[u],nt-t);
	return t;
}
```

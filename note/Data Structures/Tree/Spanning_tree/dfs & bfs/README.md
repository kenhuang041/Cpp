# dfs,bfs實現展開樹
其實就是用dfs或bfs遍歷樹的所有節點，依照經過節點順序形成的樹 <br>
比較要注意的是展開樹的定義 <br>
- 節點數與原圖G相同
- 邊數為 節點數n - 1
- 沒有還路
- 連結到所有節點

假設原圖G如下<br>
<img width="529" height="577" alt="image" src="https://github.com/user-attachments/assets/01d025a9-3d0d-4eb9-bb32-e18b6d05d1ad" />
<br>
<br>
若使用dfs實現展開數，可以得到下圖 <br>
<img width="592" height="557" alt="image" src="https://github.com/user-attachments/assets/d088ba90-1249-4ffc-8510-47c280017413" />

``` cpp
vector<int> tree[N],spanning_tree[N];
int visited[N];

void dfs(int u) {
	visited[u] = 1;
	for(auto v : tree[u]) {
		if(!visited[v]) {
			spanning_tree[u].push_back(v);
			spanning_tree[v].push_back(u);
			dfs(v);
		}
	}
}
```

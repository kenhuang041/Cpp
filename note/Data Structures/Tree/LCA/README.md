# 最近共同祖先 LCA
最近共同祖先 就字面上意思 不多說 <br>
假設樹長這樣

<img width="654" height="563" alt="image" src="https://github.com/user-attachments/assets/d2d101a4-f32d-4939-a9ad-8f4f0660dd71" />

則 節點3 跟 節點1 的最近公同祖先LCA(u,v) = 節點0

### 結構 & 原理
有兩種實現的方法，這邊先講Binary Lifting (二元跳躍法) <br>
什麼是Binary Lifting? <br>
我們可以開一個二維陣列，用來存取 節點u 的第2^i個祖先 <br>
> dp[u][0] => 節點u的第1個祖先 => 節點u的父節點<br>
> dp[u][2] => 節點u的第4個祖先 <br>
> 以圖為例，dp[4][1] => 節點4的第2個祖先 => 節點0 <br>

以此類推，我們可以得到節點u的第1,2,4...2^i個祖先 <br>
實作時也可用 dp 的方式加快執行的速度 <br>
狀態轉移式如下
``` cpp
up[u][i] = up[up[u][i-1]][i-1]
```
<img width="631" height="442" alt="image" src="https://github.com/user-attachments/assets/b8b45da2-6d2b-4885-91ec-e3699925b87f" />

圖源: https://nthu-cp.github.io/NTHU-CPP/graph/lca.html <br>
<br>
接著用dfs遍歷樹，取得所有點的祖先 <br>
``` cpp
vector<int> tree[N];
int up[N][LOG];
int depth[N];

void dfs(int u,int p) {
    up[u][0] = p;
    for(int i=1; i<LOG; i++) {
	up[u][i] = up[up[u][i-1]][i-1];
    }	
    for(auto v : tree[u]) {
	if(v != p) {
	    depth[v] = depth[u]+1;
	    dfs(v,u);
	}
    }
}
```

<br>

**查找LCA**
基本的架構完成後，就可以開始查找了，其中查找可分為
- 兩個節點調整至相同高度
- 同時向上移動，直到 i < 0;
``` cpp
int query(int u,int v) {
    if(depth[u] < depth[v]) swap(u,v); // 默認 節點u 高度 >= 節點v
    for(int i=LOG-1; i>=0; i--) { // 移動至相同高度
	if(depth[u] - (1 << i) >= depth[v]) { // depth[u] - 2^i >=  depth[v]
	    u = up[u][i]; //向上移動
	}
    }
	
    if(u == v) return u; // 相同高度時節點已相同 直接回傳
	
    for(int i=LOG-1; i>=0; i--) { // 向上移動
	//向上跳 2^i 步會不會「越過」LCA？
	if(up[u][i] != up[v][i]) { // 不會越過
	    u = up[u][i]; // 向上移動
	    v = up[v][i];
	}
    } 
	
    return up[u][0]; // 回傳結果
}
```

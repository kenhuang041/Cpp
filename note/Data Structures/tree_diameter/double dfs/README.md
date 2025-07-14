# 兩次DFS解樹直徑
我感覺蠻好理解的^^
- 先隨便挑一個點作為根節點
- dfs取得距離根節點最遠的節點u
- 在以節點u為根節點，dfs找到距離節點u最遠的節點v
- 節點u及節點v的距離就會是樹的直徑了

```cpp
void dfs(int u,int parent,int t) {
    for(auto v : tree[u]) {
	if(v == parent) continue;
	dfs(v,u,t+1);
    }	
    if(t > mx) {
	mx_node = u;
	mx = t;
    }
}
```

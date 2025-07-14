# 兩次DFS解樹直徑
我感覺蠻好理解的^^
- 先隨便挑一個點作為根節點
- dfs取得距離根節點最遠的節點u
- 在以節點u為根節點，dfs找到距離節點u最遠的節點v
- 節點u及節點v的距離就會是樹的直徑了

<br>

### 程式碼
```cpp
vector<int> tree[N];
int mx = -1,mx_node;

void dfs(int u,int parent,int t) { //當前節點 父節點 到根節點的距離
    for(auto v : tree[u]) { //遍歷當前節點的子節點
	if(v == parent) continue; //不往父節點走 避免卡遞迴
	dfs(v,u,t+1); //往子節點走
    }	
    if(t > mx) { //更新最大距離
	mx_node = u; //存取最大距離的節點
	mx = t;
    }
}
```

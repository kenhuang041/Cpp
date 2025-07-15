# 樹重心
我學到的方法，是透過節點的滲度來求樹重心

### 結構 & 原理
定義節點u的滲度為「移除節點u後，形成的若干棵子樹中節點數量中的最大值」<br>
範例如下圖，如果把左圖的節點4移除，會形成兩棵子樹 <br>
其中子樹節點數量分別是 2 和 3 <br>
則節點4的滲度應為較大的 3 <br>

|-----|-----|
| <img width="600" height="511" alt="image" src="https://github.com/user-attachments/assets/c5f3835f-3516-450f-9795-9c676327c940" /> |  <img width="615" height="357" alt="image" src="https://github.com/user-attachments/assets/533643cf-bf8b-4f52-9810-b45f6d9a5849" /> |


https://csacademy.com/app/graph_editor/

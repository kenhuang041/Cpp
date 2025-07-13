// 連鎖反應
// https://zerojudge.tw/ShowProblem?problemid=o713
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second
#define OUT (ny<0 || ny>=m || nx<0 || nx>=n)
#define LAST boom[boom.size()-1]

int m,n,q,t=1; //t統計爆炸範圍 
int a[505][505],visited[505][505];
//a存輸入內容  visited存bfs內容 
int moves[2][4] = {{0,0,1,-1},{1,-1,0,0}};

void bfs(pii start, int range) {
	range++;
	/*
	我設想的爆炸大概長這樣 (假設引爆位置為(2,2),範圍為2):
	0 0 1 0 0
	0 1 2 1 0
	1 2 3 2 1
	0 1 2 1 0
	0 0 1 0 0
	
	visited[2][2]設為2+1 代表此點還可向外擴張3格
	以此類推  visited[1][2]則剩下3-1=2格可擴張
	 
	所以range要+1 queue也需要存當前可擴張格數 ^^ 
	*/
	queue<pair<pii,int>> q; //y軸,x軸,爆炸範圍 
    	q.push({start, range});
    	visited[start.F][start.S] = range;
    
	while (!q.empty()) { //開始bfs
        pair<pii,int> cur = q.front();
	q.pop();
        int y = cur.F.F, x = cur.F.S; //當前節點y,x軸 
	int val = cur.S; //當前爆炸範圍 
		
        for (int i = 0; i < 4; i++) { //檢查上下左右是否可繼續延伸 
            int ny = y + moves[0][i];
	    int nx = x + moves[1][i];
			
		/*
		判斷是否繼續bfs的條件:
		  1.沒有超出陣列範圍
		  2.不是牆壁
		  3.此格的爆炸範圍是否大於原先的擴張格數
		(擴張格數-1 = 此格的爆炸範圍) 
		如果原先的擴張格數大於當前爆炸範圍 則代表先前以有爆炸經過 且範圍大於當前爆炸範圍
		所以就不需要繼續bfs此點了^^ 算是一種優化 
		*/
            if (!OUT && a[ny][nx]!=-1 && val-1>visited[ny][nx]) {
            	if (visited[ny][nx] == 0) t++; //總爆炸格數++ 
            
            	if (a[ny][nx] > val - 1) { //是否碰到其他炸彈 且範圍大於當前爆炸範圍
		    visited[ny][nx] = a[ny][nx]+1;
		    q.push({{ny, nx}, a[ny][nx]+1}); //bfs此點 且將範圍改為炸彈的爆炸範圍 -> a[ny][nx] 
		} 
                else {
		    visited[ny][nx] = val - 1; 
		    q.push({{ny, nx}, val - 1}); //接著bfs 
		}
	    } 
        }	
    }
} 
 
signed main() {
    IO;
    cin >> m >> n >> q;
    pii start;
    memset(visited,0,sizeof(visited));
    
    for(int i=0; i<m; i++) {
    	for(int j=0; j<n; j++) {
    	    cin >> a[i][j];
    	    if(a[i][j]==-2) { //存起始爆炸點 
    	        start.F = i;
    		start.S = j;
	    }
	}
    }
	
    int l=0,r=m*n;
    while(l<=r) { //二分搜求出解 (0 <= l,r <= m*n)
	int mid = (l+r)/2;
	t=1;
	memset(visited,0,sizeof(visited));
	bfs(start,mid); //引爆炸彈 距離為 mid 
		
	//縮小二分搜範圍 
	if(t<q) l=mid+1;
	else r=mid-1;  
    } 
	
    cout << l << endl; //輸出答案 
    return 0;
}

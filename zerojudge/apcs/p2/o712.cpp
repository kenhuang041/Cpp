// 蒐集寶石
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define OUT (a[y+moves[0][d]][x+moves[1][d]] == -1)

signed main() {
    IO;
    int m,n,k,r,c;
    cin >> m >> n >> k >> r >> c;
    int moves[2][4] = {{0,1,0,-1},{1,0,-1,0}};
    int a[m+2][n+2];
    fill(a[0],a[0]+((m+2)*(n+2)),-1);
    
    for(int i=1; i<=m; i++) {
    	for(int j=1; j<=n; j++) {
    	    cin >> a[i][j];
	    }
    }
	
	int y=r+1,x=c+1,d=0; //0=右 1=下 2=左 3=上 
	int score=0,ans=0;
	while(a[y][x] != 0) {
		score += a[y][x];
		a[y][x]--; 
		ans++;
		if(score%k == 0) d = (d+1)%4; 
		
		//cout << y << " " << x << " " << d << endl; 
		if(OUT) {
			d = (d+1)%4;
			if(OUT) d = (d+1)%4;
		}
			
		if(d==0) ++x;
		else if(d==1) ++y;
		else if(d==2) --x;
		else if(d==3) --y;
	}
	
	cout << ans;
    return 0;
}

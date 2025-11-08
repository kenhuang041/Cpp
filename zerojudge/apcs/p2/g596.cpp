// g596 動線安排
// 題目敘述很清楚 但需要注意細節

// 1. 移除順序
// 如果移除掉中間的木樁 原本的線不會自己連回去 (建木樁的時候才會連接)
//    o---o => o--oo => o   o

// 2. 連接交叉
// 每個格子一共有五種狀態: 空的、木樁、橫線、直線、交叉線
// 水平移除線的時候遇到交叉 則要將它改成橫線
// 反之垂直也是

#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first   // r
#define S second  // c
#define OUT (nr < 0 || nr >= m || nc < 0 || nc >= n)

int m,n,h,mx = -1, ans = 0;
int moves[2][4] = {{1,-1,0,0},{0,0,1,-1}}; // down, up, right, left
char a[105][105];

void find(pii rc, int d, int t) {
    int nr = rc.F + moves[0][d];
    int nc = rc.S + moves[1][d];

    vector<pii> step;
    while(!OUT && a[nr][nc] != 'o') {
        step.push_back({nr, nc});
        nr += moves[0][d];
        nc += moves[1][d];
    }

    // 判斷是連到木樁還是碰到邊界 
    if(a[nr][nc] != 'o') return; // 碰到邊界不連接
    else if(t == 0) {
        char put = (d==2 || d==3) ? '-' : '|';
        for(auto it : step) {
            if(a[it.F][it.S] != ' ' && a[it.F][it.S] != put) a[it.F][it.S] = '+';
            else a[it.F][it.S] = put;
        }
    }
    else {
        int ishor = (d==2 || d==3) ? 1 : 0;
        for(auto it : step) {
            if(a[it.F][it.S] == '+') a[it.F][it.S] = (ishor) ? '|' : '-';
            else a[it.F][it.S] = ' ';
        }
    }
}

int count() {
    int ret = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(a[i][j] != ' ') ret ++;
        } 
    } 

    return ret;
}

signed main() {
    IO;
    cin >> m >> n >> h;
    memset(a,' ',sizeof(a));

    for(int i=0,r,c,t; i<h; i++) {
        cin >> r >> c >> t;

        if(t == 0) {
            a[r][c] = 'o';
            for(int d=0; d<4; d++) find({r,c}, d, t);
        }
        else {
            a[r][c] = ' ';
            for(int d=0; d<4; d++) find({r,c}, d, t);
        }

        ans = count();
        mx = max(mx, ans);
    }

    cout << mx << "\n" << ans;
    return 0;
}

// r488 彗星撞擊
// 2025/10 新制apcs
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define OUT (i<0 || i>=r || j<0 || j>=c)
#define F first
#define S second

int r,c,d,k;
int mx=-1, mn=INT_MAX, t=0;
int a1[105][105], a2[105][105];

void bk(int a, int b, int s, int down) {
    vector<pii> step;
    s = (s-1)/2;
    int tmp=0;
    for(int i=a-s; i<=a+s; i++) {
        for(int j=b-s; j<=b+s; j++) {
            if(!OUT) {
                if(a1[i][j] > 0) {
                    a1[i][j] = -1; // 暈眩
                    tmp=1;
                }
                step.push_back({i,j});
            }
        }
    }

    if(!tmp) {
        for(auto it : step) a2[it.F][it.S] -= down;
    }
}

signed main() {
    IO;
    cin >> r >> c >> d >> k;
    memset(a1,0,sizeof(a1));
    fill(a2[0], a2[0]+(105*105), d);

    for(int i=0,y,x; i<k; i++) {
        cin >> y >> x;
        a1[y][x]++;
    }

    int m;
    cin >> m;
    for(int i=0,a,b,s,down; i<m; i++) {
        cin >> a >> b >> s >> down;
        bk(a,b,s,down);
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            mx = max(mx,a2[i][j]);
            mn = min(mn,a2[i][j]);
            if(a1[i][j] > 0) t += a1[i][j];
        }
    }

    cout << mx << " " << mn << " " << t;
    return 0;
}

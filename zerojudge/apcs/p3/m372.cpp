// m372 搬家
// bfs實作就能過了
// 記得判斷當前方向不能連接的內容 (no部分)
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second
#define N 505
#define OUT (ny<0 || ny>=n || nx<0 || nx>=m)

unordered_map<char, vector<pii>> mp = 
{
    {'F', {{1,0}, {0,1}}}, //y,x
    {'H', {{0,-1}, {0,1}}},
    {'7', {{0,-1}, {1,0}}},
    {'I', {{1,0}, {-1,0}}},
    {'L', {{0,1}, {-1,0}}},
    {'J', {{0,-1}, {-1,0}}},
    {'X', {{-1,0}, {1,0}, {0,-1}, {0,1}}},
};
map<pii, vector<char>> no = 
{
    {{-1,0}, {'H','L','J'}}, // up
    {{1,0}, {'H','7','F'}},  // down
    {{0,-1}, {'7','J','I'}}, // left
    {{0,1}, {'F','I','L'}}   // right
};

int n,m,mx=-1,visited[N][N];
char a[N][N];

int bfs(pii yx) {
    queue<pii> q;
    q.push(yx);
    visited[yx.F][yx.S] = 1;

    int ret=0;
    while(q.size() > 0) {
        pii cur = q.front();
        q.pop();
        ret++;

        vector<pii> v = mp[a[cur.F][cur.S]];
        for(auto it : v) {
            int ny = cur.F + it.F;
            int nx = cur.S + it.S;
            if(!OUT && !visited[ny][nx] && a[ny][nx] != '0') {
                vector<char> cv = no[it];
                auto it2 = find(cv.begin(), cv.end(), a[ny][nx]);
                if(it2 != cv.end()) continue;

                q.push({ny,nx});
                visited[ny][nx] = 1;
            }
        }
    }
    return ret;
}

signed main() {
    IO;
    memset(visited, 0, sizeof(visited));
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(a[i][j] != '0' && !visited[i][j]) 
                mx = max(mx,bfs({i,j}));
        }
    }

    cout << mx;
    return 0;
}

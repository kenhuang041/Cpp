// kruskal
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 1005
struct edge {
    int a,b,w;
};

vector<int> dis;
vector<edge> tree;
vector<int> spanning_tree[N];
int n,m;

bool cmp(edge a,edge b) {
    return a.w<b.w;
}

int search(int a) {
    if(dis[a] == a) return a;
    dis[a] = search(dis[a]);
    return dis[a];
}
void connect(int a,int b) {
    dis[search(a)] = search(b);
}

void kruskal() {
    sort(tree.begin(),tree.end(),cmp);
    dis.resize((n+1));
    for(int i=0; i<n; i++) dis[i] = i;
	
    int ans = 0,tmp = 0;
    for(int i=0; i<m && tmp<n-1; i++) {
	if(search(tree[i].a) != search(tree[i].b)) {
	    tmp++;
	    connect(tree[i].a,tree[i].b);
	    spanning_tree[tree[i].a].push_back(tree[i].b);
    	    spanning_tree[tree[i].b].push_back(tree[i].a);
	    ans += tree[i].w;
	}
    }
	
    cout << ans << "\n";
}

signed main() {
    IO;
    cin >> n >> m; //點 邊 
    for(int i=0,a,b,w; i<m; i++) {
	cin >> a >> b >> w;
	tree.push_back({a,b,w});
    } 
    kruskal();
	
    for(int i=0; i<10; i++) {
	cout << i << ": ";
	for(auto it : spanning_tree[i]) {
	    cout << it << " ";
	}
	cout << "\n";
    }
	
    return 0;
} 
/*
7 8
0 1 3
0 2 1
1 3 1
3 4 2
4 5 1
5 1 1
5 2 7
2 6 5
*/

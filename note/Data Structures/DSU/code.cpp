#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 10005
int p[N];

int find(int x) {
	if(p[x] == x) return x;
	return p[x] = find(p[x]); //路徑壓縮 + 遞迴 
}

void Union(int x,int y) {
	int g1 = find(x);
	int g2 = find(y);
	if(g1 != g2) p[g2] = g1; // 合併集合 
}

signed main() {
    IO;
    int n = 10;  
    for(int i=0; i<n; i++) {
        p[i] = i;
    }

    Union(1, 2);
    Union(2, 3);
    Union(4, 5);

    cout << (find(1) == find(3) ? "Yes\n" : "No\n"); // YES
    cout << (find(1) == find(4) ? "Yes\n" : "No\n"); // NO
}

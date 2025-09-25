#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

struct edge
{
    int a, b, w;
};

vector<int> dsu;
vector<edge> g;
int n, m;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (dsu[x] == x)
        return x;
    dsu[x] = find(dsu[x]);
    return dsu[x];
}

void kruskal()
{
    sort(g.begin(), g.end(), cmp);
    dsu.resize(n + 1);
    for (int i = 0; i <= n; i++)
        dsu[i] = i;

    int ans = 0;
    for (edge it : g)
    {
        int g1 = find(it.a);
        int g2 = find(it.b);
        if (g1 != g2)
        {
            dsu[g2] = g1;
            ans += it.w;
        }
    }

    cout << ans;
}
int main()
{
    IO;
    edge tmp;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp.a >> tmp.b >> tmp.w;
        g.push_back(tmp);
    }
    kruskal();
    return 0;
}

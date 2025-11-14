// q839 分組遊戲
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
#define IO                       \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define N 505

struct edge
{
    int a, b, w;
};

vector<edge> g;
vector<int> v;
int n, k;

int find(int x)
{
    if (v[x] == x)
        return x;
    v[x] = find(v[x]);
    return v[x];
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

void kruskal()
{
    sort(g.begin(), g.end(), cmp);
    v.resize(n + 1);
    for (int i = 0; i <= n; i++)
        v[i] = i;

    int ans = 0, c = n;
    for (int i = 0; i < g.size(); i++)
    {
        int g1 = find(g[i].a);
        int g2 = find(g[i].b);
        if (g1 != g2)
        {
            v[g2] = g1;
            c--;
            if (c == k)
            {
                ans = INT_MAX;
                for(int j=i; j<g.size(); j++) {
                    int g3 = find(g[j].a);
                    int g4 = find(g[j].b);
                    if(g3 != g4) {
                        cout << g[j].w;
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    IO;
    edge e;
    int mn = INT_MAX;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0, w; j < n; j++)
        {
            cin >> w;
            if (w > 0)
                mn = min(mn, w);
            if (i < j && w > 0)
            {
                e.a = i;
                e.b = j;
                e.w = w;
                g.push_back(e);
            }
        }
    }

    if (k == n)
        cout << mn << "\n";
    else
        kruskal();

    return 0;
}

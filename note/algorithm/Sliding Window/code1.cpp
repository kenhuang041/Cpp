// 可以用deque實現 但比較多行
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
#define int long long

int a[N];
deque<int> dp;

void op(int n, int k)
{
    while (!dp.empty() && dp.front() < n - k + 1)
      dp.pop_front();

    while (!dp.empty() && a[dp.back()] < a[n])
      dp.pop_back();

    dp.push_back(n);
}

signed main()
{
    IO;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        op(i, k);
        if (i >= k - 1)
        {
            cout << a[dp.front()] << " ";
        }
    }

    return 0;
}

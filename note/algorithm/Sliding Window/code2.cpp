// 滑動窗口 求子陣列大小為k的最大數字總和
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

signed main()
{
    IO;
    int n, k, sum = 0, ans = -1;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i < k) // 先累加前k項
            sum += a[i];
    }

    for (int i = k; i < n; i++)
    {
        sum += a[i]; // 新增一項
        sum -= a[i - k]; // 刪掉最後面一項
        ans = max(ans, sum); // 取解
        cout << sum << "\n";
    }

    cout << ans;
    return 0;
}

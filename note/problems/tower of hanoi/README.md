# 河內塔
### 題目敘述
有三根柱子，目前有n個盤子在柱子A <br>
一次只能搬一個盤子，則怎樣按照相同順序將盤子移至柱子C? <br>
看不懂的話，可以看這個: https://www.mathsisfun.com/games/towerofhanoi.html <br>

<br>

### 思路
如果要依照之前小在上、大在下的順序，是不是要先把最大的搬到柱子C? <br>
思路是: 如果要把最下面的盤子由 柱子A(起點) 到 柱子C(終點)，則先將上面的所有盤子移動到B(經過點?)，再移動最下面的盤子至柱子C <br>
這樣的話柱子B形成了一個新的盤子堆 <br>
套用之前的邏輯，就可以慢慢把盤子排到柱子C了 <br>

```  cpp
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pic pair<int,char>
#define int long long
#define F first
#define S second
#define endl "\n"

void solve(int n,int from, int to, int aux) {
    if(n == 1) {
        cout << from << " " << to << endl;
        return;
    }

    solve(n-1, from, aux, to);
    cout << from << " " << to << endl;
    solve(n-1, aux, to, from);
}

signed main() {
    IO;
    int n;
    cin >> n;
    solve(n,1,3,2);    
    return 0;
}
```

<br>

### 題目
https://cses.fi/problemset/task/2165

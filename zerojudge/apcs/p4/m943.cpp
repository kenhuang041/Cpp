// m943 合併成本
/*
假設目前要合併範圍 2~5 ，則:
    1. 可能有很多合併選擇 例如合併區間2~4和區間5、區間2~3及區間4~5等等
                   
這邊開了一個迴圈，就是為了遍歷所有可能的區間合併方式，並找到最佳切法
其中 dp[i][k] 代表左區間最小成本， dp[k+1][j] 代表右區間最小成本
則求當前 dp[i][j] 最小成本的狀態轉移式應為: 左區間最小成本 + 右區間最小成本 + 左右區間合併成本
                   
pv存的是是前綴和，所以:
    1. pv[k]-pv[i-1] 是左區間總和
    2. pv[j]-pv[k]   則是右區間總和

dp[i][j] 是最小成本，所以每次算出cost都要和原內容比較並取最小值
*/

#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second
#define N 200005

signed main() {
    IO;
    int n;
    cin >> n;
    vector<int> p(n+1), pv(n+1);
    for(int i=1; i<=n; i++) {
        cin >> p[i];
        pv[i] = pv[i-1] + p[i];
    }

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int l=2; l<=n; l++) {
        for(int i=1; i+l-1<=n; i++) {
            int j = i+l-1;
            dp[i][j] = LLONG_MAX;

            for(int k=i; k<j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + llabs((pv[k]-pv[i-1]) - (pv[j]-pv[k]));
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    for(auto v : dp) {
        for(auto it : v) { 
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
7
30 35 15 5 10 20 25
*/ 

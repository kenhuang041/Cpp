// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=87&mosmsg=Submission+received+with+ID+30647298
// 經典的Josephus Problem (約瑟夫問題)
// 參考: https://hackmd.io/@vax-r/rJRJVa1Dq

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define N 10005

int f(int n,int m) {
    int ans = 0; //只有一人 則安全位置為0 
    for (int i = 2; i <= n; i++) {
        ans = (ans + m) % i; //加上新的人 參照上次結果算出新的存活位置 
        // i=2: 存活位置 = (0 + 7) % 2 = 1
        // i=3: 存活位置 = (1 + 7) % 3 = 2 
        // 從上一個安全位置開始 +7算出新的安全位置 
    }
    return ans+1; // 改 1-indexed 
}

signed main() {
    IO;
    int n,m;
    while(cin >> n&&n) {
    	if(n == 13) { // 一個一個關 所以m=1 
    		m=1;
		}
		else {
			m=2; 
			while(f(n-1,m) != 12) m++; //找到最小m
			//n-1 是為了保證第13號存活
			// f(n-1, m) 計算前 n-1 個人的最後生存位置
            // 我們希望最後停留的位置是 12，這樣第 n (=13) 號人就安全
		}
    	cout << m << endl;
	}
    return 0;
}

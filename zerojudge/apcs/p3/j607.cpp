// j607 先加後乘與函數
// 第一次解這種題目 光是輸入就讓我想了段時間 ==
// 用 read() 判斷當前輸入是 數字 還是 f
// 是 f 的話就呼叫 f() 處理，反之就用 solve() 正常運算
// 因為是先加後乘 所以要先處理加法 
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define int long long
#define F first
#define S second

// cin 緩衝區
// 如果輸入是 2+f(8,2*3)
// 則緩衝區狀態為  ['2','+','f','(','8',',','2','*','3',')']

int f();
int read();
int solve();

int f() {
    char tmp;
    int mx = -1, mn = INT_MAX;
    cin >> tmp;

    while(true) {
        int value = solve();

        mx = max(mx,value);
        mn = min(mn,value);

        cin >> tmp;
        if(tmp == ')') break;
    }
    
    return (mx-mn);
}

int read() {
    char ch;
    cin >> ch;

    if(isdigit(ch)) {
        cin.putback(ch);
        int x; 
        cin >> x;
        return x;
    }
    else if(ch == 'f') {
        return f();
    }
}

int solve() {
    int a,b;
    a = read();
    char ch;
    
    while(cin >> ch) {
        if (ch == '+') {
        	b = read();
        	a += b;
		}
        else if (ch == '*') {
        	a *= solve();
		}
        else {
            cin.putback(ch); 
            // 如果 ch == ')', 則將輸入放回緩衝區 
            // 回到 f() 以後接 cin >> tmp
			// 後續沒有輸入 所以讀到的是 cin 緩衝區的 ')' 
            break;
        }
    }

    return a;
}

signed main() {
    IO;
    char ch;
    int a, ans = 0;
	cout << solve();
    return 0;
}

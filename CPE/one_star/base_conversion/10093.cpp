// https://zerojudge.tw/ShowProblem?problemid=n786
#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int value(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'Z') return c - 'A' + 10;
    if ('a' <= c && c <= 'z') return c - 'a' + 36;
    return 0;
}

int main() {
    IO;
    string s;
    while (cin >> s) {
        vector<int> val;
        int sum = 0, maxd = 0;
        for (char c : s) {
            int v = value(c);
            val.push_back(v);
            sum += v;
            maxd = max(maxd, v);
        }

        int ans = -1;
        for (int n = max(2, maxd + 1); n <= 62; n++) {
            if (sum % (n - 1) == 0) {
                ans = n;
                break;
            }
        }

        if (ans == -1) cout << "such number is impossible!\n";
        else cout << ans << "\n";
    }
    return 0;
}

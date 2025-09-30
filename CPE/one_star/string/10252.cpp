// https://zerojudge.tw/ShowProblem?problemid=e507
// 找字串a和b中的共同字元 排序並輸出
// 用兩個map紀錄字元 如果同時存在於m1跟m2 則取數量較小者 並儲存至ans
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    while (cin >> s1 >> s2) {
        map<char, int> m1, m2;
        for (auto c : s1) m1[c]++;
        for (auto c : s2) m2[c]++;
        
        vector<char> ans;
        for (auto it : m1) {
            char c = it.first;
            if (m2.find(c) != m2.end()) {
                int min_count = min(m1[c], m2[c]);
                for (int i = 0; i < min_count; i++) {
                    ans.push_back(c);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        for (auto c : ans) cout << c;
        cout << endl;
    }
    return 0;
}

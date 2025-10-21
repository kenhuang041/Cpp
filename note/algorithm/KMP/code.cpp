#include <bits/stdc++.h>
using namespace std;

vector<int> build(string &t) {
    vector<int> F(t.size());
    F[0] = -1;
    for (int i = 1, pos = -1; i < t.size(); i++) {
        while (~pos && t[i] != t[pos + 1])
            pos = F[pos];
        if (t[i] == t[pos + 1])
            pos++;
        F[i] = pos;
    }
    
    for(auto it : F) cout << it << " ";
	cout << endl; 
    return F;
}

vector<int> kmp_search(string &s, string &t) {  
    vector<int> F = build(t); // 建立LPS
    vector<int> res;
    int pos = -1; // 代表上一次成功比到哪個索引，所以使用時要 + 1 
    
    for (int i=0; i<s.size(); i++) {
    	// ~pos => pos != -1
        while (~pos && s[i] != t[pos + 1]) // 配對失敗時，回到 t 的最長相等前後綴的最後一個索引
            pos = F[pos];
        
        if (s[i] == t[pos + 1]) // 配對成功，pos移動至下個配對點 
            pos++;
            
        if (pos + 1 == t.size()) { // 比對成功 
            res.push_back(i - pos);
            pos = F[pos];
        }
    }
    
    return res;
}

int main() {
    string s = "abababac";
    string t = "ababac";
    vector<int> match = kmp_search(s, t);
    // for (int i : match) cout << "found at " << i << endl;
}

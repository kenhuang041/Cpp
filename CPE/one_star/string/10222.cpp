// https://zerojudge.tw/ShowProblem?problemid=e578
// 輸出內容 對應 輸入內容在鍵盤內的位置向左移動兩格
// 所以 k 對應的是 h
// 不會有不合理的情況 例如a
// 把合理的情況都輸入到map內即可 
//   '\'要用\\、'''要用'\''
//   空白不用變

#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

map<char,char> mp = {
    {'2','`'},
    {'3','1'},
    {'4','2'},
    {'5','3'},
    {'6','4'},
    {'7','5'},
    {'8','6'},
    {'9','7'},
    {'0','8'},
    {'-','9'},
    {'=','0'},
    {'e','q'},
    {'r','w'},
    {'t','e'},
    {'y','r'},
    {'u','t'},
    {'i','y'},
    {'o','u'},
    {'p','i'},
    {'[','o'},
    {']','p'},
    {'\\','['},
    {'d','a'},
    {'f','s'},
    {'g','d'},
    {'h','f'},
    {'j','g'},
    {'k','h'},
    {'l','j'},
    {';','k'},
    {'\'','l'},
    {'c','z'},
    {'v','x'},
    {'b','c'},
    {'n','v'},
    {'m','b'},
    {',','n'},
    {'.','m'},
    {'/',','},
    {' ',' '},
};

int main()
{
    IO;
    string s;
    while(getline(cin,s)) {
        for(auto c : s) cout << mp[c];
        cout << "\n";
    }

    return 0;
}

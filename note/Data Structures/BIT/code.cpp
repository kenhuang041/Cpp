#include <iostream>
using namespace std;

const int N = 200005;  // 可依需求擴大
int a[N];              // 原始資料陣列
int bt[N];             // Binary Indexed Tree

// 取得最低有效位元
int lowbit(int x) {
    return x & -x;
}

// 建構 BIT：把 a[1]~a[n] 加進 BIT
void build(int n) {
    for (int i = 1; i <= n; i++) {
        for (int x = i; x < N; x += lowbit(x)) {
            bt[x] += a[i];
        }
    }
}

// 單點加值：a[x] += k，同步更新 BIT
void add(int x, int k) {
    a[x] += k;
    for (int i = x; i < N; i += lowbit(i)) {
        bt[i] += k;
    }
}

// 單點修改：a[x] = k（直接指定值）
void modify(int x, int k) {
    int delta = k - a[x];  // 計算差值
    add(x, delta);         // 用差值進行更新
}

// 前綴和查詢：a[1] + ... + a[x]
int find(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += bt[i];
    }
    return sum;
}

// 區間查詢：a[l] + ... + a[r]
int query(int l, int r) {
    return find(r) - find(l - 1);
}

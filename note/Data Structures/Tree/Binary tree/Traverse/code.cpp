#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
struct node {
    int val = -1,left = -1,right = -1;
};

node tree[35];
int n;

void preorder(node now) { // 前序: 根節點 -> 左子節點 -> 右子節點
    if(now.val == -1) return;
    cout << now.val << " ";
    if(now.left != -1) preorder(tree[now.left]);
    if(now.right != -1) preorder(tree[now.right]);
}

void inorder(node now) { // 中序: 子左節點 -> 根節點 -> 右子節點 
    if(now.val == -1) return;
    if(now.left != -1) inorder(tree[now.left]);
    cout << now.val << " ";
    if(now.right != -1) inorder(tree[now.right]);
}

void postorder(node now) { // 後序: 左子節點 -> 右子節點 -> 根節點 
    if(now.val == -1) return;
    if(now.left != -1) postorder(tree[now.left]);
    if(now.right != -1) postorder(tree[now.right]);
    cout << now.val << " ";
}


signed main() {
    IO;
    cin >> n;
    for(int i=0,u,l,r; i<n; i++) {
    	cin >> u >> l >> r;
    	tree[u].val = u;
    	tree[u].left = l;
    	tree[u].right = r;
    }
	
    preorder(tree[0]);
    cout << "\n";
    inorder(tree[0]);
    cout << "\n";
    postorder(tree[0]);
}

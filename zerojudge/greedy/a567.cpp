//https://zerojudge.tw/ShowProblem?problemid=a567
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second

int main() {
	int n,ans;
	while(cin >> n) {
		priority_queue<pii> pq;
		int a[n+1] = {0};
		ans=0;
		
		int d,p;
		for(int i=0; i<n; i++) {
			cin >> d >> p;
			pq.push({p,d});
		}
		
		while(!pq.empty()) {
			auto now = pq.top();
			pq.pop();
			p = now.F;
			d = now.S;
			for(int j=d; j>=1; j--) {
				if(!a[j]) {
					a[j] = p;
					ans += p;
					break;
				}
			}
		}
    
		cout << ans << endl;
	}
	
	return 0;
}

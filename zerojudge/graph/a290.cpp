// https://zerojudge.tw/ShowProblem?problemid=a290
#include<bits/stdc++.h> 
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
	IO;
	int n,m,a,b;
	while(cin >> n >> m) {
		vector<int> v[n+1];
		
		for(int i=0; i<m; i++) {
			cin >> a >> b;
			v[a].push_back(b);
		}
		cin >> a >> b;
		
		//bfs
		queue<int> q;
		int visited[n+1],bk=0;
		memset(visited,0,sizeof(visited));
		q.push(a);
		while(q.size() > 0) {
			int curr = q.front();
			visited[curr] = 1;
			q.pop();
			
			for(auto i: v[curr]) {
				if(i == b) {
					cout << "Yes!!!\n";
					bk=1;
					break;
				}
				else if(!visited[i]){
					q.push(i);
					visited[i] = 1;
				}
			}
			
			if(bk) break;
		}
		
		if(!bk) cout << "No!!!\n";
	}
	return 0;
}

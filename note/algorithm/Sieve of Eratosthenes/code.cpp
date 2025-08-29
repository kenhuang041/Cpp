// zerojuudge a007
#include<bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define N 46341

signed main() {
    IO;
    bool a[N];
    int n;
    vector<int> v;
    memset(a,0,sizeof(a));
    a[0] = 0;
    a[1] = 0;
	
    for(int i=2; i<N; i++) {
	    if(!a[i]) {
	        v.push_back(i);
	        for(int j=i*i; j<N; j+=i) {
		        a[j] = 1;
	        }
	    }
    }
	
    while(cin >> n) {
	    if(n > N) {
	        bool no = 0;
	        for(auto it : v) {
		        if(pow(it,2) > n) break;
		        if(n%it == 0) {
		            no = 1;
		            break;
		        }
	        }
			
	        if(!no) cout << "質數\n";
	        else cout << "非質數\n";
	    }
	    else {
	        if(!a[n]) cout << "質數\n";
	        else cout << "非質數\n";
	    }
    }
    return 0;
}
 

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long n,c[3] = {1,5,10};
	cin >> n;
	
	long arr[n+1] = {0};
	
	arr[0] = 1;
		
	for(long i=0; i<3; i++){
		for(long j=c[i]; j<n+1; j++){
			arr[j] += arr[j - c[i]];
			//j - c[i]代表 
			//假設11，那就是取11-10=1這格的內容加上原本[11]的內容 
		}
	}
	
	for(int j=0; j<n+1; j++){
		cout << arr[j] << " ";
	}
	
	return 0;
}

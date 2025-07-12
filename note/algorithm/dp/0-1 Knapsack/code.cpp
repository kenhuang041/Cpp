#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n+1][9] = {0},a[n+1],b[n+1]; //9是題目指定的背包容量8再加上1
	
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }
	
    for(int i=1; i<=n; i++){
        for(int j=0; j<9; j++){ 
            if(j-a[i-1] < 0){
                arr[i][j] = arr[i-1][j];
            }
            else{
                arr[i][j] = max(arr[i-1][j],arr[i-1][j-a[i-1]]+b[i-1]);
            }
        }
    }
	
    cout << arr[n][8];
    return 0;
}

# 找零錢問題

<font color=#F7A004>[例題]</font>
>目前有三種硬幣，分別是1、5、10。則有幾種方法可以用這三種硬幣湊出11元?   
>
如果要用動態規劃來解這題的話，那麼也需要用陣列來理解對吧~
**(圖片內紅色字為更新的內容)**

### <font color=#1936C9>解法</font>
<font color=#000000>
    <font color=#FFFFFF>開一個大小為11+1的陣列，裡面的值如圖所示</font>
<font color=#000000>
    
    
![chrome_4eIhTUb0Dv](https://hackmd.io/_uploads/HkBkGcJG0.png)
    <font color=#FFFFFF>如果只有1元一種硬幣的話，則代表每個數都可以湊出來，所以每格都加1(不包含arr[0])</font>
</font>

![chrome_x6OcJQLSpz](https://hackmd.io/_uploads/ryN1r9JfR.png)


<font color=#FFFFFF>但當有1元和5元兩種硬幣時，那麼就代表陣列內>=5的格子都會多一種組合(多了5)，如下圖</font>
<font color=#FF0000>**(10跟11會多一種組合: 兩個5。所以才會是3)**</font>

![chrome_QAm27tzxyO](https://hackmd.io/_uploads/SJc7Sckz0.png)

<font color=#FFFFFF>如果再加入10元的話，陣列就會變成變成這樣</font>

![chrome_QAm27tzxyO](https://hackmd.io/_uploads/B19iS5yMA.png)

<br>
    
<font color=#FFFFFF>道理懂了吧，接下來看看該如何用動態規劃實現吧 :D</font>

### <font color=#1936C9>程式碼</font>
``` cpp=
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

```

# 01背包問題
題目主要理念是:
**將一堆物品塞進背包內，在限制背包容量的前提下，使背包內物品價值最大化**
而其中01的意思是，每一項物品只會放進背包內0個(沒有放)或者是1個

<font color=#F7A004>**[例題]**</font>
>輸入n，並在接下來的n行輸入其容量及價格
如果限制包包的容量為8，則其最大價格為何?

如果是優先挑選價值最高的物品放入背包，則有可能會浪費掉背包的空間，價值也可能不如全放容量少的東西直至背包全滿

要解出此題的話也可以用窮舉法，找出物品的所有搭配並取最大價值者，不過缺點就是，時間複雜度太高了(O(2^n*n))

**這時候就可以用效率更高的動態規劃來實現此題啦~**

### <font color=#1936C9><br>思路</font>
先創建一個二維陣列，其中縱向為每個物品的編號，橫向為0~8個容量

![1714041499678](https://hackmd.io/_uploads/H1VSWiJzC.jpg)

如果背包容量為0或是物品編號為0(不存在)的話，就甚麼東西都裝不下了，如下圖

![1714041499686](https://hackmd.io/_uploads/SyR8Wi1MR.jpg)

但如果到(2,1)時，物品編號1的容量為2，並且能夠剛好放進背包內。此時我們需要在(2-2,1-1)的位置加上物品編號1的價格3以及(2,1-1)的0中取最大值並填入，則(2,1)填入3

<font color=#FF0000>**2-2指的是目前背包容量2減掉物品編號1的容量2，1-1代表物品編號1已經裝不下了，所以返回至上一項看裝了多少**</font>
<font color=#FF0000>**(2,1-1)代表現在這一項物品裝不進去，所以回去看上一項的能不能裝下**</font>

![1714041499690](https://hackmd.io/_uploads/Skk6ZjyGR.jpg)

依此累推，(3,2)能在背包為3的情況下剛好裝進背包，所以在(3-3,2-1)的值0+物品價格4與(3,2-1)的3中取最大值，也就是4。

![1714041499699](https://hackmd.io/_uploads/ByUAbi1zR.jpg)

**全部填完長這樣 (如果要最大價格的話，那就取表格右下角的格子，也就是10)**

![1714041499672](https://hackmd.io/_uploads/B1zlGiJGC.jpg)

### <font color=#1936C9><br>程式碼</font>
``` cpp=
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
```

### <font color=#1936C9><br>類題</font>
[b184.裝貨櫃問題](<https://zerojudge.tw/ShowProblem?problemid=b184>)

[d637.路過的鴨duck](<https://zerojudge.tw/ShowProblem?problemid=d637>)

### <font color=#1936C9><br>參考資料</font>
[背包問題_影片_01](<https://www.bilibili.com/video/BV1K4411X766/?spm_id_from=333.337.search-card.all.click>)

[背包問題_影片_02](<https://www.bilibili.com/video/BV1pY4y1J7na/?spm_id_from=333.337.search-card.all.click>)

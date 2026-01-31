#include<stdio.h>
#include <stdlib.h>

int main() {
  int n;scanf("%d",&n);
  int *arr=(int *)malloc((n+1)*sizeof(int ));
  int *cnt=(int *)calloc(n+1,sizeof(int));
  for (int i=1;i<=n;i++) {scanf("%d",&arr[i]);}
  //从后往前遍历
  for (int i=n;i>=1;i--) {
    for (int j=2*i;j<=n;j+=i) {
        if (cnt[j]==1){cnt[i]^=1;}
    }//cnt数组用于积累前面的影响
    if ((arr[i]^cnt[i])==1) {
      cnt[i]=1;
    }
    else{cnt[i]=0;}//这里cnt数组用于记录是否按下电灯
  }
  //输出数组ans
  for (int i=1;i<=n;i++) {
    if (cnt[i]==1){printf("%d ",i);}
  }
  free(arr);
  free(cnt);
  return 0;
}


/*思维：原本的n*根号n的时间复杂度-》nlogn在于因数的查找变成了倍数的查找，最终是调和级数求和就是logn
 *方法：
 *1。01转换：^=
 *2.因数影响：倍数方法（逆转思维
*/
#include<bits/stdc++.h>
using namespace std;
int test,n,i,a[10005],sum;
int main(){
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%n)puts("-1");
        else{
            sum/=n;
            printf("%d\n",3*n-3);
            for(i=2;i<=n;i++){
                printf("1 %d %d\n",i,(i-a[i]%i)%i);
                printf("%d 1 %d\n",i,(a[i]+i-1)/i);
            }
            for(i=2;i<=n;i++)printf("1 %d %d\n",i,sum);
        }
    }
}

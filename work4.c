#include <stdio.h>

int main(){
    int n;
    scanf_s("%d",&n);
    const int N=n;
    int m[N],x[N];
    for(int i=0;i<N;i++)
        scanf_s("%d %d",&m[i],&x[i]);
    int count,fit;
    for(count=1;;count++){
        fit=0;
        for(int i=0;i<N;i++)
            fit+=count%m[i]==x[i];
        if(fit==N)
            break;
    }
    printf("%d",count);
    return 0;
}

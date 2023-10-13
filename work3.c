#include <stdio.h>

int main(){
    int x=1,z=1,y=1,k;
    k=x++||++y&&++z;
    printf("%d %d %d",x,y,z);
    return 0;
}
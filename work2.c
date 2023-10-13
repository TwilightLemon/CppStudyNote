#include <stdio.h>
#include <math.h>

int Factorial(int n){
    int value=1;
    for(int i=1;i<n+1;i++)
        value*=i;
    return value;
}

int main(){
    double x,n,res=0;
    scanf_s("%lf %lf",&x,&n);
    for(int i=0;i<n;i++){
        res+=pow(x,i)/ Factorial(i);
    }
    printf("%.6f",res);
    return 0;
}

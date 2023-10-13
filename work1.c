#include <stdio.h>
#include <windows.h>

void Print99Chart(){
    for(int i=1;i<10;i++){
        for(int x=1;x<i+1;x++){
            printf("%d x %d = %d  ",i,x,i*x);
        }
        printf("\n");
    }
}

int main(){
    int result;
    do{
        double i;
        result=scanf("%lf",&i);

        if(result)
            printf("the number you entered is:%lf\n",i);
        else{
            fflush(stdin);
            printf("it isn't a num !!!\n");
        }
    }while(!result);
    system("pause");
    //交作业时删除
    Print99Chart();
    system("pause");
    //到这里
    return 0;
}
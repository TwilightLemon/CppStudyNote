#include<stdio.h>
#include<string.h>
#define N 4
//请编写代码输出两个字符串中所有相同位置上的相同字符
int main(){
    char str1[N];
    printf("请输入一个字符串:");
    gets(str1);
    char str2[N];
    printf("再输入下一个字符串:");
    gets(str2);
    for(int i=0;i<N;i++){
        if(str1[i]==str2[i]) {
            printf("%c", str1[i]);
        }
    }
    return 0;
}
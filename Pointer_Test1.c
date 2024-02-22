/*
 * Created by TwilightLemon on 9/20/2023.
 * 指针与数组
 * 对应教程：https://www.runoob.com/cplusplus/cpp-arrays.html
 * 示例中的函数mostFrequentChar用于统计字符串中最多的字母
 *
 * */

#include <stdio.h>

void mostFrequentChar(const char *str,char *result,int *count){
    const char *p=str;
    char list[26]={0};
    int score[26]={0};
    while(*p!='\0'){
        (*p-'a')[list]=*p;//一种很抽象的写法，不过这里是为了将字符映射到数组中
        (*p-'a')[score]++;//统计每个字符出现的次数
        //从上面你可以发现，这里的list和score都是数组的首地址，下标访问的实质是指针的偏移
        //运算符[]的实质就是加法运算和解引用运算的结合
        p++;
    }
    int maxIndex=0;
    for(int i=0;i<26;i++)
        if(*(score +i)>*(score+maxIndex))
            maxIndex=i;
    //将结果通过指针返回是从函数得到多个结果比较常见的做法
    *result=maxIndex[list];
    *count=score[maxIndex];
}

int main(){
    const char *str="abccccceeeedddddddddd";
    char result;
    int count;
    mostFrequentChar(str,&result,&count);
    printf("%c %d",result,count);
    return 0;
}
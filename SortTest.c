//
// Created by TwilightLemon on 10/16/2023.
//三种排序算法：冒泡、选择、插入
//提供了测试函数，可以测试排序算法的性能
//参考：https://www.runoob.com/w3cnote/ten-sorting-algorithm.html
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct SortedResult{
    int step;
    int *list;
};
void swap(int *a,int *b);
struct SortedResult BobbleSort(int *list,int length);
struct SortedResult SelectionSort(int *list,int length);
struct SortedResult InsertionSort(int *list,int length);
int* TestSortFunc(char *name,int *list,int len,struct SortedResult func(int[],int));

int main(){
    const int len=10000;
    int list[len];
    for(int i=0;i<len;i++)
        list[i]=rand();

    int *result = TestSortFunc("Insertion Sort",list,len,InsertionSort);

    for(int i=0;i<len;i++){
        printf("%d ",result[i]);
    }
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int* TestSortFunc(char *name,int *list,int len,struct SortedResult func(int[],int)){
    time_t start=clock();
    struct SortedResult res = func(list,len);
    time_t end=clock();
    printf("%s: Total steps:%d Finished in: %dms\n",name,res.step,(int)end-start);
    return res.list;
}
struct SortedResult InsertionSort(int *list,int length){
    int count=0;
    for(int i=1;i<length;i++){
        int index=i,value=list[i];
        while(index>0&&value<list[index-1]){
            list[index+1]=list[--index];
            count++;
        }
        list[index]=value;
    }
    struct SortedResult res={count,list};
    return res;
}
struct SortedResult SelectionSort(int *list,int length){
    int count=0,minIndex;
    for(int i=0;i<length-1;i++){
        minIndex=i;
        for(int m=i+1;m<length;m++){
            if(list[i]>list[m])
                minIndex=m;
            count++;
        }
        if(minIndex!=i)
            swap(&list[i],&list[minIndex]);
    }
    struct SortedResult res={count,list};
    return res;
}

struct SortedResult BobbleSort(int *list,int length){
    int count=0,swapped;
    for(int i=0;i<length;i++){
        swapped=0;
        for(int e=0;e<length;e++){
            if(list[e+1]<list[e]){
                swap(&list[e+1],&list[e]);
                swapped=1;
            }
            count++;
        }
        if(swapped==0)
            break;
    }
    struct SortedResult res={count,list};
    return res;
}
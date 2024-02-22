//
// Created by TwilightLemon on 10/13/2023.
// 常见排序算法的c++实现，同SortTest.c
//教程在这里  https://www.runoob.com/w3cnote/ten-sorting-algorithm.html
//
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

class SortedResult{
public:
    int count;
    vector<int> list;
};

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

SortedResult BobbleSort_v1(vector<int> list,int length){
    int count=0;
    for(int i=0;i<length;i++){
        for(int e=0;e<length;e++){
            if(list[e+1]>list[e]){
                swap(list[e+1],list[e]);
            }
            count++;
        }
    }
    return SortedResult{count,list};
}

SortedResult BobbleSort_v2(vector<int> list,int length){
    int count=0;
    bool swapped;
    for(int i=length-1;i>0;i--){
        for(int e=0;e<i;e++){
            swapped= false;
            if(list[e+1]>list[e]){
                swap(list[e+1],list[e]);
                swapped=true;
            }
            count++;
        }
        if(!swapped)break;
    }
    return SortedResult{count,list};
}

SortedResult BobbleSort_v2_Double(vector<int> list,int length){
    int count=0;
    bool swapped;
    for(int i=length-1;i>0;i--){
        for(int e=0;e<i;e++){
            swapped= false;
            if(list[e+1]>list[e]){
                swap(list[e+1],list[e]);
                swapped=true;
            }
            count++;
        }
        if(!swapped)break;
    }
    return SortedResult{count,list};
}

SortedResult SelectSort(vector<int> list,int length){
    int temp,maxIndex,count=0;
    for(int i=0;i<length;i++){
        maxIndex=i;
        for(int j=i+1;j<length;j++){
            if(list[j]>list[maxIndex])
                maxIndex=j;
        }
        if(maxIndex!=i) {
            temp = list[i];
            list[i] = list[maxIndex];
            list[maxIndex] = temp;
        }
        count++;
    }
    return SortedResult{count,list};
}

SortedResult InsertSort_v2(vector<int> list,int length){
    int count=0;
    for(int i=1;i<length;i++){
        int index=i;
        int value=list[i];
        while(index>0&&value>list[index-1]){
            list[index+1]=list[--index];
            count++;
        }
        list[index]=value;
    }
    return SortedResult{count,list};
}

SortedResult ShellSort(vector<int> list, int length) {
    int gap,temp,count=0;
    for (gap = length >> 1; gap > 0; gap >>= 1)
        for (int i = gap; i < length; i++) {
            temp = list[i];
            int j = i - gap;
            for (; j >= 0 && list[j] < temp; j -= gap)
                list[j + gap] = list[j];
            list[j + gap] = temp;
            count++;
        }
    return SortedResult{count,list};
}

SortedResult BucketSort(vector<int> list,int length){
    //桶排序
    //step1.找到最大值和最小值
    int max=list[0],min=list[0];
    for(int i=1;i<length;i++) {
        if (list[i] > max)max = list[i];
        if (list[i] < min)min = list[i];
    }
    //step2.创建桶
    int bucketNum=(max-min)/length+1;
    vector<vector<int>> bucket(bucketNum);
    //step3.把元素放入桶中
    for(int i=0;i<length;i++){
        int index=(list[i]-min)/length;
        bucket[index].push_back(list[i]);
    }
    //step4.对每个桶进行排序
    for(int i=0;i<bucketNum;i++){
        //偷懒了，直接用了标准库的排序方法 第三个参数可选，表示排序规则
        std::sort(bucket[i].begin(),bucket[i].end(),std::greater<>());
    }
    //step5.把桶中的元素放回原数组
    list.clear();
    for(int i=0;i<bucketNum;i++){
        for(int e : bucket[i]){
            list.push_back(e);
        }
    }
    return SortedResult{-1,list};
}

void TestSortFunc(string name,vector<int> list,SortedResult func(vector<int>,int)){
    auto start=system_clock::now();
    auto res_ins = func(list,list.size());
    auto end=system_clock::now();
    cout<<name<<":Total steps: "<<res_ins.count<<" Finished in "<<duration_cast<microseconds>(end-start).count()/1000.0<<"ms"<<endl;
}

int main(){
    vector<int> list;
    int length=50000;
    for(int i=0;i<length;i++)
        list.push_back(rand());

    TestSortFunc("Shell Sort", list, ShellSort);
    TestSortFunc("Insert Sort", list, InsertSort_v2);
    TestSortFunc("Select Sort", list, SelectSort);
    TestSortFunc("Bobble Sort", list, BobbleSort_v2);
    TestSortFunc("Bucket Sort", list, BucketSort);

    return 0;
}


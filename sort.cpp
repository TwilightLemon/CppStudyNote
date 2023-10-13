//
// Created by cz241 on 10/13/2023.
//
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

int BobbleSort_v1(int list[],int length){
    int count=0;
    for(int i=0;i<length;i++){
        for(int e=0;e<length;e++){
            if(list[e+1]>list[e]){
                swap(list[e+1],list[e]);
            }
            count++;
        }
    }
    return count;
}

int BobbleSort_v2(int list[],int length){
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
    return count;
}

int SelectSort(int *list,int length){
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
            count++;
        }
    }
    return count;
}

int InsertSort(int *list,int length){
    int count=0;
    for(int i=1;i<length;i++){
        for(int j=i-1;j>=0;j--){
            if(list[j]<list[j+1]){
                swap(list[j],list[j+1]);
                count++;
            }
        }
    }
    return count;
}

int InsertSort_v2(int *list,int length){
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
    return count;
}

int ShellSort(vector<int> &list, int length) {
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
    return count;
}

int main(){
    time_t start=clock();
    vector<int> list;
    int length=10000;
    for(int i=0;i<length;i++)
        list.push_back(rand());
    cout<<"Origin:"<<endl;
    for(int i :list)
        cout<<i<<" ";

    int count = ShellSort(list,length);
    time_t end=clock();
    cout<<"\nSorted:"<<endl;
    for(int i :list)
        cout<<i<<" ";
    cout<<"\nTotal steps: "<<count<<" Finished in "<<end-start<<"ms"<<endl;

    return 0;
}


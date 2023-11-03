#include<iostream>
#include<cstdio>
#include <vector>
using namespace std;

int main()
{
    int input;
    int success = scanf_s("%d",&input);
    vector<int> list;
    while(success&&input>0){
        list.push_back(input);
        success = scanf_s("%d",&input);
    }
    if(list.empty()){
        cout<<0;
        return 0;
    }
    int size=list.size();
    int minValue=list[0];
    for(int i=1;i<size;i++){
        if(list[i]<minValue)
            minValue=list[i];
    }
    cout<<minValue;
}
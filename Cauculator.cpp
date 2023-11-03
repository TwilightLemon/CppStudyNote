//
// Created by cz241 on 10/23/2023.
//
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

int main(){
    stack<int> list;
    char in;
    for(scanf("%c",&in);in!='\n'; scanf("%c",&in)){
        if(in==' ')continue;
        if(in>='0'&&in<='9')
            list.push(int(in-'0'));
        else{
            int a=list.top();
            list.pop();
            int b=list.top();
            list.pop();
            int res;
            switch(in){
                case'+':
                    res=a+b;
                    break;
                case'-':
                    res=a-b;
                    break;
                case'*':
                    res=a*b;
                    break;
                case'/':
                    res=a/b;
                    break;
            }
            list.push(res);
        }
    }

    cout<<list.top()<<endl;
    return 0;
}
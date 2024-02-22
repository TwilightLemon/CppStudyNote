//
// Created by TwilightLemon on 9/20/2023.
//只是为了测试一下lambda表达式
//对应教程:https://www.runoob.com/cplusplus/cpp-functions.html
//
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int i=1;
    cout<<i<<endl;
    auto func=[&]()->string{
        i=5;
        return "done.";
    };
    cout<<func()<<endl;
    cout<<i<<endl;
    return 0;
}
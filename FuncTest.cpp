//
// Created by cz241 on 9/20/2023.
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
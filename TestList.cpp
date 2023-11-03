//
// Created by cz241 on 10/19/2023.
//
#include <iostream>
#include <list>
using namespace std;

list<int> l;
int main(){
    for(int i=0;i<10;i++){
        l.push_back(rand());
    }
    l.sort();

    for(auto item : l){
        cout<<item<<" ";
    }
    l.reverse();
    cout<<endl;
    for(auto p=l.begin();p!=l.end();p++){
        cout<<*p<<" ";
    }
    return 0;
}
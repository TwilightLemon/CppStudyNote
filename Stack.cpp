//
// Created by cz241 on 10/16/2023.
//
#include <iostream>
using namespace std;

class Stack{
    int count=0,*ptr,*list,size;
public:
    Stack(int Size):size(Size){
        list=new int[Size];
    }
    ~Stack(){
        delete[] list;
    }
    bool is_empty(){
        return count==0;
    }
    bool is_full(){
        return count==size;
    }
    bool push(int value){
        if(is_full())
            return false;
        if(count)ptr++;
        else ptr=&list[0];
        *ptr=value;
        count++;
        return true;
    }
    int pop(){
        if(count==0)
            return NULL;
        count--;
        int value=*ptr;
        ptr--;
        return value;
    }
    void print(){
        if(count==0)return;
        for(int*p=&list[0];p<=ptr;p++){
            cout<<*p<<"  ";
        }
    }
};
int main(){
    Stack* s= new Stack(5);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);
    s->push(5);

    s->print();

    s->pop();
    s->pop();
    s->pop();
    s->print();

    return 0;
}
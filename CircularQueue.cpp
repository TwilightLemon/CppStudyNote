//
// Created by TwilightLemon on 10/16/2023.
// 循环队列(先进先出)的简单实现
//
#include <iostream>
#include <cassert>
using namespace std;

class Queue{
    int *head,*tail;
    int *list;
    int size,count=0;
public:
    Queue(int Size):size(Size){
        list=new int[Size];
        head=&list[0];
        tail= &list[0];
    }
    ~Queue(){
        delete[] list;
    }

    bool append(int value){
        if(count==size)//队列已满
            return false;
        if (tail == list+size - 1) {//尾指针在数组末尾
            tail = &list[0];
        } else if(count!=0) tail++;//非空情况下尾指针后移
        count++;
        *tail = value;
        return true;
    }
    int pop(){
        if(count==0)//队列为空
            return NULL;
        int value=*head;
        if (head == &list[size - 1]) {
            head = &list[0];
        } else head++;
        count--;
        return value;
    }
    bool is_empty(){
        return count==0;
    }
    void print(){
        int* h=head;
        while(h!=tail){
            cout<<*h<<"  ";
            if(h==&list[size-1])
                h=&list[0];
            else h++;
            if(h==tail)
                cout<<*h<<"  ";
        }

    }
};

int main(){
    Queue* q=new Queue(3);

    q->append(1);
    q->append(2);
    q->append(3);
    q->print();


    assert(q->pop()==1);
    q->append(4);
    assert(q->pop()==2);
    q->append(5);
    assert(q->pop()==3);
    q->append(6);


    q->print();
    cout<<q->is_empty();

    return 0;
}
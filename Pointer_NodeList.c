/*
 *简易单向链表的创建和反转
 * */
#include <stdio.h>
#include <malloc.h>

typedef struct node{
    int value;
    struct node *next;
} node;

node* createList(int firstValue){
    node* p=(node*)malloc(sizeof(node));
    p->value=firstValue;
    p->next=NULL;
    return p;
}
node* push_back(node* node1,int value){
    node* new=(node*) malloc(sizeof(node));
    new->next=NULL;
    new->value=value;
    node1->next=new;
    return new;
}

node* reverse(node* head){
    node* p=head;
    node* q=NULL;
    while(p){
        node* temp=p->next;
        p->next=q;
        q=p;
        p=temp;
    }
    return q;
}

int main(){
    node* head=createList(10);
    node* last=head;
    for(int i=9;i>0;i--) {
        last=push_back(last, i);
    }
    head=reverse(head);
    while(head){
        printf("%d  ",head->value);
        printf("%p  **p: %p\n",head,&head);
        head=head->next;
    }
    return 0;
}
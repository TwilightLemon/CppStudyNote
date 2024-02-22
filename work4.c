//某人的链表作业题
#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct stu
{
    int num;
    char name[21];
    struct stu*next;
};
struct stu *head=NULL;
int count=0;
void insert(int num,char *name){
    count++;
    //没有则新建一个Head
    if(head==NULL){
        head=(struct stu *)malloc(sizeof(struct stu));
        head->num=num;
        strcpy(head->name,name);
        head->next=NULL;
        return;
    }
    struct stu *p=head;
    //找到最后一个比num小的节点
    while(p->next!=NULL&&p->next->num<num){
        p=p->next;
    }
    struct stu *q=(struct stu *)malloc(sizeof(struct stu));
    q->num=num;
    strcpy(q->name,name);
    //如果head->num>num,则插入到head前面
    if(p==head){
        q->next=head;
        head=q;
        return;
    }
    q->next=p->next;
    p->next=q;
}
void printReverse(){
    struct stu *p=head;
    //不用真的反转链表，只需要把指针存起来，然后倒序输出就行了
    struct stu *list[count];
    for(int i=0;i<count;i++){
        list[i]=p;
        p=p->next;
    }
    for(int i=count-1;i>=0;i--){
        printf("%d, %s\n",list[i]->num,list[i]->name);
    }
}
void found(int num){
    struct stu *p=head;
    struct stu *list[count];
    for(int i=0;i<count;i++){
        list[i]=p;
        p=p->next;
    }
    p=head;
    int index=0;
    while(p!=NULL){
        if(p->num==num){
            break;
        }
        p=p->next;
        index++;
    }
    if(p==NULL){
        printf("ERROR");
    }else{
        //输出前一个
        printf("%d, %s\n",list[index-1]->num,list[index-1]->name);
        //输出后一个，如果存在
        if(index+1<count)
            printf("%d, %s\n",list[index+1]->num,list[index+1]->name);
    }
}
int main(){
    int num;
    char name[21];
    while(1){
        int success=scanf("%d, %s",&num,name);
        //success=2表示成功读取了两个变量,没有的话就是到了查询的那一行
        if(success!=2){
            break;
        }
        insert(num,name);
    }
    printReverse();
    found(num);
    return 0;
}
/*
 * 简陋的文件操作+链表练习题
 * 实现功能：从指定文件中读取商品id和name
 *                 创建链表
 *                 添加新商品并保存至文件
 * */

#include <stdio.h>
#include <malloc.h>
#include <strsafe.h>

struct Box{
    int id;
    char name[20];
};
struct NodeList{
    struct Box box;
    struct NodeList *next;
};

int main(){
    char *filename=(char *)malloc(100*sizeof(char));
    printf("Enter file name: ");
    scanf("%s",filename);
    FILE *f=fopen(filename,"a+");
    if(f==NULL){
        printf("ERROR... FAILED TO OPEN.\n");
        return 0;
    }

    struct NodeList *head=NULL;
    struct NodeList *tail=NULL;

    while(!feof(f)){
        struct NodeList *node=(struct NodeList *)malloc(sizeof(struct NodeList));
        int s1=fscanf(f,"%d",&node->box.id);
        int s2=fscanf(f,"%s",node->box.name);

        if(s1!=1||s2!=1){//读取失败，可能是到达文件尾
            break;
        }

        node->next=NULL;
        if(head==NULL){
            head=node;
            tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
    }
    //显示已读入信息
    struct NodeList *p=head;
    while(p!=NULL){
        printf("Read as : %d %s\n",p->box.id,p->box.name);
        p=p->next;
    }
    printf("ADD: id name:\n");
    //添加信息
    int add_id;
    char add_name[20];
    scanf("%d %s",&add_id,add_name);
    //写入文件
    fprintf(f,"%d %s\n",add_id,add_name);
    fclose(f);
    //释放链表
    p=head;
    while(p!=NULL) {
        struct NodeList* next=p->next;
        free(p);
        p=next;
    }
    return 0;
}
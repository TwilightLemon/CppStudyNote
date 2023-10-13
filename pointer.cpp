#include <stdio.h>
#include <iostream>

using namespace std;

int* Get(){
    int* p=new int[3];
    p[0]=1;
    p[1]=2;
    p[2]=3;
    return p;
}

int main()
{
    int* p=Get();
    for(int i=0;i<3;i++){
        printf("%d\n",p[i]);
    }
    delete[] p;

    char s[]="Hellow.";
    cout<<(void*)&s[0]<<endl;

    float a=2.0/3.0;
    printf("%1.9f",a);

    return 0;
}
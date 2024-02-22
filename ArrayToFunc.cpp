/*
 * create by TwilightLemon
 * date:2024.1.2
 *
 * 一个传递二维数组给函数的例子
 * */
#include <iostream>
using namespace std;

//传递二维指针给函数
bool Find(int **Map,int Cow,int Line,int value){
    bool found=false;
    for(int x=0;x<Cow;x++){
        for(int y=0;y<Line;y++){
            int a=*(*(Map+x)+y);//等价于Map[x][y]
            if(a==value)
                found = true;
            cout<<a<<"  ";
        }
    }
    return found;
}
//传递指针数组给函数  Map是一个指针数组，每个元素都是一个指针 而Map本身是一个指向指针的指针
bool Find_1(int *Map[],int Cow,int Line,int value){
    bool found=false;
    for(int x=0;x<Cow;x++){
        for(int y=0;y<Line;y++){
            int a=Map[x][y];
            if(a==value)
                found = true;
            cout<<a<<"  ";
        }
    }
    return found;
}
//传递指针给函数  这里说明了二维数组的内存分布是连续的
bool Find_2(int *Map,int Cow,int Line,int value){
    bool found=false;
    for(int x=0;x<Cow;x++){
        for(int y=0;y<Line;y++){
            int a=*(Map+x*Line+y);//等价于Map[x][y]
            if(a==value)
                found = true;
            cout<<a<<"  ";
        }
    }
    return found;
}

//当然你也可以直接写成数组形式，只不过这样必须指定第二维的大小
bool Find_3(int Map[][3],int Cow,int Line,int value){
    bool found=false;
    for(int x=0;x<Cow;x++){
        for(int y=0;y<Line;y++){
            int a=Map[x][y];
            if(a==value)
                found = true;
            cout<<a<<"  ";
        }
    }
    return found;
}

int main()
{
    int m[][3]={{1,2,3},{2,3,4},{3,4,5}};
    int *p[3]={m[0],m[1],m[2]};

    Find(p,3,3,5);
    Find_1(p,3,3,5);

    Find_2(&m[0][0],3,3,5);
    Find_2(m[0],3,3,5);

    Find_3(m,3,3,5);
    return 0;
}
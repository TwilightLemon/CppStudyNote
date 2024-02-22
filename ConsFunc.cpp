#include <iostream>

using namespace std;
static int count=0;
static int dcount=0;
class A{
public:
    A(const A &a){//[拷贝构造函数]
        cout<<"Copy"<<endl;
    }
    A(){//默认构造函数
        count++;
        cout<<"A"<<count<<endl;
    }
    A(int a){//带参数的构造函数
        count++;
        cout<<"B"<<count<<endl;
    }
    ~A(){//析构函数
        dcount++;
        cout<<"~A"<<dcount<<endl;
    }
};

void Func(A a){
    cout<<"Func invoked."<<endl;
}

int main()
{
    A a,b(1),c[5],*p;//构造函数调用了7次
    Func(a);//调用了一次 拷贝构造函数
    count=0;
    p=new A[2];//构造函数调用了2次,由于是堆内存，所以析构函数不会自动调用
    delete []p;//手动释放  析构函数调用了2次
    count=0;
    A *m=&a;//用指针指向已有的对象，不会调用构造函数

    return 0;
}


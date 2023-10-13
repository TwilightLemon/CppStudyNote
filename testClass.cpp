//
// Created by cz241 on 9/20/2023.
//
#include <iostream>
using namespace std;

class Box{
public:
    friend class Namer;
    Box(double x,double y,double z):x(x),y(y),z(z){
       cout<<"create"<<endl;
    }
    Box(Box& b){//拷贝构造函数
        cout<<"create by replication"<<endl;
    }
    ~Box(){
        cout<<"Disposed."<<endl;
    }
    double x,y,z;
    double GetVolume(){
        return x*y*z;
    }
private:
    int id;
};
class Namer{
public:
    static void SetName(Box& b,int id){
        b.id=id;
    }
    static int GetName(Box& b){
        return b.id;
    }
};
void CrackOne(Box b){
    cout<<"Cracked"<<endl;
}

Box& CreateOne(){
    Box a(1,1,1);
    return a;
}
int main(){
   // Namer::SetName(CreateOne(),12);
    Box b=CreateOne();
    cout<<b.GetVolume()<<endl;
    Namer::SetName(b,10);
    cout<<Namer::GetName(b)<<endl;
    CrackOne(b);
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Person{
    string name;
    int age;
    string dic;
};

struct Profession{
    string name;
    vector<Person> members;
};
vector<Profession> School;

int main(){
    system("chcp 65001");
    Profession software={"软件系"};
    Person p1={"张三",30,"人工智能"};
    Person p2={"李四",40,"数据库"};

    vector<Person> members;
    members.push_back(p1);
    members.push_back(p2);

    software.members=members;
    School.push_back(software);
    Profession bigdata={"大数据"};
    School.push_back(bigdata);

    for(Profession p : School){
        cout<<p.name<<":"<<endl;
        for(Person per : p.members)
            cout<<"Name:"<<per.name<<"  Age:"<<per.age<<"  Research Direction:"<<per.dic<<endl;
    }
    system("pause");
    return 0;
}
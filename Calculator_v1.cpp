//
// Created by cz241 on 10/23/2023.
//
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

int main(){
    int isNum;
    stack<double> list;
    for(;;){
        string st;
        cin>>st;
        char  *n;
        double num= strtod(st.c_str(),&n);
        isNum=*n=='\0';
        if(isNum){
            list.push(num);
        }
        else{
            char op;
            op=st[0];

            if(op=='e')break;
            else if(op==' ')continue;

            double a=list.top();
            list.pop();
            double b=list.top();
            list.pop();
            double res;
            switch(op){
                case'+':
                    res=a+b;
                    break;
                case'-':
                    res=a-b;
                    break;
                case'*':
                    res=a*b;
                    break;
                case'/':
                    res=a/b;
                    break;
            }
            list.push(res);
        }
    }
    cout<<list.top()<<endl;
    return 0;
}
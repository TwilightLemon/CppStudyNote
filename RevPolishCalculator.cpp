/*
* Created by TwilightLemon on 10/23/2023.
*这是一个逆波兰表达式计算器
*格式如下：
* num1 num2 op num3 op ... =
* 其中num1,num2,num3...是数字，op是运算符，=表示结束
*每个数字和运算符之间用空格隔开
*例如：
*12.89 166.1 + 2 * 0.8 / =
*输出：0.00223476
*/
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

            if(op=='=')break;
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
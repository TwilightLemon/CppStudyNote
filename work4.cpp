#include <iostream>

using namespace std;

int main(){
    int a,b,c,d,r1,result,i=0;
    cin>>a>>b>>c>>d;
    while(i>=0){
        switch(i){
            case 0:
                r1=a+b;
                break;
            case 1:
                r1=a-b;
                break;
            case 2:
                r1=a*b;
                break;
            case 3:
                if(b)
                    r1=a/b;
                break;
            default:
                i=-2;
                if(result!=24)
                    cout<<"NOT"<<endl;
                break;
        }
        i++;
        for(int p=0;p<4;p++){
            int r2=r1;
            switch(p){
                case 0:
                    r2+=c;
                    break;
                case 1:
                    r2-=c;
                    break;
                case 2:
                    r2*=c;
                    break;
                case 3:
                    if(c)
                        r2/=c;
                    break;
            }
            for(int k=0;k<4;k++){
                int r3=r2;
                switch(k){
                    case 0:
                        r3+=d;
                        break;
                    case 1:
                        r3-=d;
                        break;
                    case 2:
                        r3*=d;
                        break;
                    case 3:
                        if(d)
                            r3/=d;
                        break;
                }
                result=r3;
                if(r3==24) {
                    cout << "YES" << endl;
                    return 0;
                }
            }

        }
    }
    return 0;
}

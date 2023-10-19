//
// Created by cz241 on 10/14/2023.
//
#include <iostream>
using namespace std;



int main(){
    int lang[]={1,2,3,4};
    int p1[2]={4},p2[2],p3[2],p4;
    for(int i=0;i<3;i++){
        p1[1]=i+1;
        for(int x:lang){
            p4=x;
            for(int y : lang){
                //乙不会英语
                if(y==2)continue;
                p2[0]=y;
                for(int y1:lang){
                    if(y1==y)continue;
                    p2[1]=y1;
                    for(int q : lang){
                        //丁不会日语
                        if(q==4)continue;
                        p3[0]=q;
                        for(int q1:lang){
                            if(q1==q)continue;
                            p3[1]=q1;
                            //E.
                            if(p1[0]+p1[1]==7||p2[0]+p2[1]==7||p3[0]+p3[1]==7)
                                continue;
                            //D: 不能直接交流
                            if(p1[0]==p3[0]||p1[0]==p3[1]||p3[0]==p4||p3[1]==p4)
                                continue;
                            //D: 乙丙可以交流
                            if(p2[0]==p3[0]||p2[1]==p3[1]){
                                //C.
                                if((p1[0]==4||p1[1]==4)&&(p3[0]!=4&&p3[1]!=4)&&(p2[0]!=2&&p2[1]!=2)){
                                    //B:
                                    int all[]={p1[0],p1[1],p2[0],p2[1],p3[0],p3[1],p4};
                                    int count[4]={0,0,0,0};
                                    for(int p:all)
                                        count[p-1]++;
                                    int out=0;
                                    for(int c : count){
                                        out+=c==3;
                                    }
                                    if(out!=1)continue;

                                    printf("%d %d\n%d %d\n%d %d\n%d end\n",p1[0],p1[1],p2[0],p2[1],p3[0],p3[1],p4);
                                }
                            }


                        }
                    }

                }
            }
        }
    }
    return 0;
}
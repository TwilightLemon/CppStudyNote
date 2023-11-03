#include <iostream>

using namespace std;

bool Find(int **Map,int Cow,int Line,int value){
    bool found=false;
    for(int x=0;x<Cow;x++){
        for(int y=0;y<Line;y++){
            int a=*(*(Map+x)+y);//Map[x][y]
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

    return 0;
}
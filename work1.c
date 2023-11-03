#include <stdio.h>

double scores[5][4]={{78.1,82,93,74}
                                ,{62,82.2,72,76},
        {100,90,85.3,72},
        {67,89,90,65},
        {77,88,99,45}};
double GetAverage(int student){
    double sum=0;
    for(int i=0;i<4;i++){
        sum+=scores[student][i];
    }
    return sum/4;
}
int main(){
    double average[5];
    for(int i=0;i<5;i++){
        double aver=GetAverage(i);
        average[i]=aver;
        printf("student %d average score is %.2f\r\n",i+1,aver);
    }
    //rank echo student's average score:
    for(int i=1;i<5;i++){
        for(int j=0;j<5-i;j++){
            if(average[j+1]>average[j]){
                double temp=average[j];
                average[j]=average[j+1];
                average[j+1]=temp;
            }
        }
    }
    printf("rank:\r\n");
    for(int i=0;i<5;i++){
        printf("student %d average score is %.2f\r\n",i+1,average[i]);
    }
    return 0;
}
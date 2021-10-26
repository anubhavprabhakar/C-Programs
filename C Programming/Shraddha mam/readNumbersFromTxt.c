#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main(){
    double arr1[6], arr2[6];
    int i=0;
    FILE *f;
    double num;
    
    f = fopen("numbers.txt", "rb");
    
    if(f==NULL){
        puts("\nCannot open file");
        exit(1);
    }

    while(i<6 && (fscanf(f, "%lf", &num))!=EOF){
        arr1[i]=num;
        i++;
    }
    
    i=0;

    while(i<6 && (fscanf(f, "%lf", &num))!=EOF){
        arr2[i]=num;
        i++;
    }


    printf("\nData read from text file:\n");
    for(i=0; i<6; i++){
        printf("%lf\n", arr1[i]);
    }
    for(i=0; i<6; i++){
        printf("\n%lf", arr2[i]);
    }

    fclose(f);
    return 0;
}
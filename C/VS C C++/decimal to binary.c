#include <stdio.h>

int main(){
    int binary, counter, n, number;
    binary=0, counter=1;
    printf("Enter a decimal number");
    scanf("%d", &n);
    number=n;
    while(n!=0){
        if(counter==1){
            binary=n%2;
        }
        counter*=10;
        n=n%2;
        binary=counter*(n%2)+binary;
    }
    printf("\nBinary for %d is = %d", number, binary);
    return 0;
}
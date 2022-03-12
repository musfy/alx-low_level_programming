#include<stdio.h>

int main() {
    int x = 20;
    char y = 'a';
    //Using variable names as input
    printf("The size of int is: %d\n", sizeof(x));
    printf("The size of char is %d\n", sizeof(y));
    //Using datatype as input
    printf("The size of float is: %d\n", sizeof(float));
    return 0;
}

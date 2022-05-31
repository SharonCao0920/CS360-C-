#include<stdio.h>

int main(){

int a, b, temp;

printf("enter the number for a");

scanf("%d", & a);

printf("enter the number for b:");

scanf("%d, & b");

temp = a;

a= b;

b= temp;

printf("after switching the number in a is = %.2d\n", & a);

printf("after switching the number in b is = %.2d\n", & b);

return 0;
}
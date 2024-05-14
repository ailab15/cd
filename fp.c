#include<stdio.h>
int main(){
char operator;
int num1,num2,result;
FILE *fp=fopen("input.txt","r");
fscanf(fp,"%d %c %d",&num1,&operator,&num2);

switch(operator){
    case '+':
        result=num1+num2;
        break;
    default:
        printf("Invalid operator");
}
fclose(fp);
FILE *pp=fopen("input.txt","a");
fprintf(pp,"The result is %d",result);
fclose(pp);
}
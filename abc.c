#include<stdio.h>
#include <string.h>

int main(){
    char left[50], right[50],temp[10],productions[25][50];
    int i=0,j=0,consumed=0,flag=0;
    printf("Enter productions:");
    scanf("%1s->%s",left,right);
    printf("%s",right);
    while(sscanf(right+consumed,"%[^|]s",temp)==1 && consumed<=strlen(right)){
        if(temp[0]==left[0]){
            flag=1;
            sprintf(productions[i++],"%s->%s%s'\0",left,temp+1,left);
        }
        else{
            sprintf(productions[i++],"%s'->%s%s'\0",left,temp,left);
        }
        consumed+=strlen(temp)+1;
    }
    if(flag==1){
        sprintf(productions[i++],"%s->e\0",left);
        printf("The productions after eliminating left recursion are:");
        for(j=0;j<i;j++){
            printf("%s\n",productions[j]);
        }

    }
    else{
        printf("No Left recursion");
    }
    return 0;
}
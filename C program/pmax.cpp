#include <stdio.h>
 
int main()
{
    int i,j;
    char CH='G';
    int space=1;
 
    for(i=1; i<=5; i++)
    {
        //first part of the row
        for(j='A'; j<=CH; j++)
            printf("%c",j);
 
        //remove last character of first part of first row
        if(i==1)
            printf("\b");
 
        //spaces between first, second part of the row
        for(j=1; j<space; j++)
            printf(" ");
 
 
        for(j=CH; j>='A'; j--)
            printf("%c",j);
 
        printf("\n");
        CH--;
        space++;
    }
 
    return 0;
}

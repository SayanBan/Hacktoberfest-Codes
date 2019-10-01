#include<stdio.h>
int main()
{
   char i,j,s=1,k;
   for(i='G';i>='A';i--)
   {
   	for(j='A';j<=i;j++)
   	{
   		printf("%c",j);
	}
	for(k=s;k>1;k--)
	{
		printf("\n");
	}
	for(j=i;j>=1;j--)
	{
		printf("%c",j);
	}
	printf("\n");
	s++;
   }
}

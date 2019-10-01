#include<stdio.h>
int main()
{
	int i,j,k;
	for(i=0;i<5;i++)
	{
		for(k=4;k>=1;k--)
		{
			printf(" ");
		}
		for(j=0;j<=i;j++)
		{
			printf("%c",j+65);
		}
		printf("\n");
	}
	return 0;
}

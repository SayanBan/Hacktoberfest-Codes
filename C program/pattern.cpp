#include<stdio.h>
main()
{
	int n,i,j,k;
	int z=1;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n-1;j>=i;j--)
		{
			printf("");
		}
		for(k=1;k<=z;k++)
		{
			printf("%d",z);
		}
		z+=2;
		printf("\n");
	}
    return 0;
}

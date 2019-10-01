#include<stdio.h>
main()
{
	int a,b,c;
	printf("enter the 3 numbers\n");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	if(a>b&&a>c)
	{
		printf("%d is the greatest of three\n",a);
	}
	if(b>a&&b>c)
	{
		printf("%d is the greatest number of three\n",b);
	}
	else
	{
	printf("%d is the greatest number of three\n",c);
	}
	return 0;
}

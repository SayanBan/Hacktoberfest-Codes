#include<stdio.h>
#include<conio.h>
main()
{
	int a,b,c,d,e;
	int f;
	printf("write any two nos.\n");
	scanf("%d %d",&a,&b);
	c=a+b;
	d=a-b;
	e=a*b;
	f=a/(float)b;
	printf("sum = %d\n",c);
	printf("difference = %d\n",d);
	printf("product = %d\n",e);
	printf("division = %d\n",f);
	return 0;
}


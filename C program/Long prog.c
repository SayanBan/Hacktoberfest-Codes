#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
	int i,testc,n,nby3,nby5,pint;
	scanf("%d", &testc);
	while(testc--)
	{
		scanf("%d", &n);
		if (n<3)
		{
			printf("-1\n");
			continue;
		}
		nby5=n%5;
		if (nby5==0)
		{
			pint=(n>=15)?1:0;
			if (pint)
				while(n>=15)
				{
					printf("555555555555555");
					n-=15;
				}
			for (i = 0; i < n; ++i)
				printf("3");
			printf("\n");
		}
		else if (nby5==1)
		{
			if (n-6<0)
			{
				printf("-1\n");
				continue;
			}
			pint=(n-6)>=15?1:0;
			if (pint)
				while(n-6>=15)
				{
					printf("555555555555555");
					n-=15;
				}
			printf("555555");
			for (i = 0; i < n-6; ++i)
				printf("3");
			printf("\n");
		}
		else if (nby5==2)
		{
			if (n-12<0)
			{
				printf("-1\n");
				continue;
			}
			pint=(n-12)>=15?1:0;
			if (pint)
				while(n-12>=15)
				{
					printf("555555555555555");
					n-=15;
				}
			printf("555555555555");
			for (i = 0; i < n-12; ++i)
				printf("3");
			printf("\n");
		}
		else if (nby5==3)
		{
			if (n-3<0)
			{
				printf("-1\n");
				continue;
			}
			pint=(n-3)>=15?1:0;
			if (pint)
				while(n-3>=15)
				{
					printf("555555555555555");
					n-=15;
				}
			printf("555");
			for (i = 0; i < n-3; ++i)
				printf("3");
			printf("\n");
		}
		else if (nby5==4)
		{
			if (n-9<0)
			{
				printf("-1\n");
				continue;
			}
			pint=(n-9)>=15?1:0;
			if (pint)
				while(n-9>=15)
				{
					printf("555555555555555");
					n-=15;
				}
			printf("555555555");
			for (i = 0; i < n-9; ++i)
				printf("3");
			printf("\n");
			
		}
	}
	return 0;
}

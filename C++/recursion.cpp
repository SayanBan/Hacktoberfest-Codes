#include<stdio.h>
#include<conio.h>
int fact(int n)
{
    if (n <= 1) 
        return 1;
    else    
        return n*fact(n-1);    
}
int gcd(int n1, int n2) {
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}
int fibo(int n) 
{ 
    if (n == 0) 
        return 0; 
    if (n == 1 || n == 2) 
        return 1; 
    else
        return (fibo(n - 1) + fibo(n - 2)); 
} 
 void toh(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    toh(n-1, from_rod, aux_rod, to_rod); 
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    toh(n-1, aux_rod, to_rod, from_rod); 
} 
 int main()
{        while(1){

      int x,n,n1,n2;
       printf("\n Enter 1: For finding factorial of a number \n");
       printf(" Enter 2: For Finding GCD of two numbers \n");
       printf(" Enter 3: For fibonacci series \n");
       printf(" Enter 4: for Tower of Hanoi \n");
       
	   scanf("%d",&x);
	   
	   switch(x){
	   	
	   	case 1: printf("Enter the number for finding its factorial \n");
	   	         scanf("%d",&n);
	   	         printf("\n Factorial of %d is ",n);
		          printf("%d \n",fact(n));
		           printf("\n");
	   	           break;
	   	   
    	case 2:  printf("Enter two positive integers: ");
                 scanf("%d %d", &n1, &n2);
				  printf("G.C.D of %d and %d is %d.", n1, n2, gcd(n1, n2));
				   printf("\n");
		         	break;
		         	
		case 3: printf("Enter the number of terms in fibonacci series \n");
		         scanf("%d",&n);
		         printf("\n fibonacci series is \n");
		        for(int i=0;i<n;i++){
		        	printf("%d ",fibo(i));
				} 
				 printf("\n");
		           break;	
		           
		case 4:printf("Enter the Number of plates \n");
		       scanf("%d",&n);
		       printf("A is initial Rod , B is Final Rod and C is auxillary Rod \n");
		       toh(n,'A','B','C');
		       printf("\n");
		       break;
	  
	   } 
        
       
  }
 }

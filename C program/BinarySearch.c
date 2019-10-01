#include<stdio.h>
    int main(){
        
        
        int A[10],i,j,temp,item;
        
        printf("Array Elements\n");
        
        for(i = 0;i<10;i++)
        scanf("%d",&A[i]);
        
        for(i=0;i<9;i++){
        for(j=i+1;j<10;j++){
        
        if(A[i]>A[j]){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        }
        }
        }
        
        printf("Sorted Array\n");
        for(i=0;i<10;i++)
        printf("%d ",A[i]);
        
        printf("\n");
        
        int F = 0;
        int L = 9;
        int flag = -1;
        int MP = (F+L)/2;
        
        printf("\n");
        scanf("%d",&item);
        
        while(F<=L && flag!=1){
            
            MP = (F+L)/2;
            
            if(A[MP]==item){
            flag = 1;
            break;
        }       
        else if(A[MP]>item)
        L=MP-1;
        else if(A[MP]<item)
        F=MP+1;
        
    }
    
    if(flag==-1)
    printf("Not Found");
    else
    printf("Found at %dth position",(MP+1) );
    
    return 0;
}

import random
import time
import sys

sys.setrecursionlimit(10**8) 


def insertion(A,l):
	S = [m for  m in range(0, 5000)]
	print("\n A----",A[0:20])
	print("\n -----",S[0:20])
	start=time.time()
	for j in range(1,l):
	
		x=A[j]
		y=S[j]
		i=j-1
		while i>=0 and A[i]>x :
			A[i+1]=A[i]
			S[i+1]=S[i]
			i=i-1

		A[i+1]=x
		S[i+1]=y
	end=time.time()
	print("\n -----",S[0:20],"\n-----/n")
	return (A,end-start)




def merge(A,p,q,r): 
    n1=q-p+1
    n2=r-q
    L=[0]*(n1) 
    R=[0]*(n2)  
    for i in range(0,n1): 
        L[i]=A[p+i] 
  
    for j in range(0,n2): 
        R[j]=A[q+1+j] 
    i=0     
    j=0    
    k=p        
    while i<n1 and j<n2 : 
        if L[i]<=R[j]: 
            A[k]=L[i] 
            i=i+1
        else: 
            A[k]=R[j] 
            j=j+1
        k=k+1
    while i<n1 : 
        A[k]=L[i] 
        i=i+1
        k=k+1
    while j<n2 : 
        A[k]=R[j] 
        j=j+1
        k=k+1 
def mergeSort(A,p,r): 
    start=time.time()
    if p<r:  
        q=(p+(r-1))//2   
        mergeSort(A,p,q) 
        mergeSort(A,q+1,r) 
        merge(A,p,q,r)
    end=time.time() 
    return (A,end-start)




def partition_endpivot(A,p,r,S):
	x=A[r]
	z=S[r]
	i=p-1
	for j in range(p,r):
		if A[j]<=x :
			i=i+1
			y=A[i]
			A[i]=A[j]
			A[j]=y
			q=S[i]
			S[i]=S[j]
			S[j]=q
	y=A[i+1]
	A[i+1]=A[r]
	A[r]=y
	q=S[i+1]
	S[i+1]=S[r]
	S[r]=q
	return (i+1)

def quickSort_endpivot(A,p,r,S):	
	start=time.time()
	if p<r :
		q=partition_endpivot(A,p,r,S)
		quickSort_endpivot(A,p,q-1,S)
		quickSort_endpivot(A,q+1,r,S)
	end=time.time()
	return (A,end-start)

def partition_startpivot(A,p,r):
	i=p+1
	x=A[p]
	for j in range(p+1,r+1):
		if x>=A[j] :
			y=A[i]
			A[i]=A[j]
			A[j]=y
			i=i+1
	y=A[p]
	A[p]=A[i-1]
	A[i-1]=y
	return (i-1)  

def quickSort_startpivot(A,p,r):
	start=time.time()
	if p<r :
		q=partition_startpivot(A,p,r)
		quickSort_startpivot(A,p,q-1)
		quickSort_startpivot(A,q+1,r)
	end=time.time()
	return (A,end-start)
	
def partition_randompivot(A,p,r):
	i=random.randint(p,r)
	y=A[r]
	A[r]=A[i]
	A[i]=y
	i=p
	for j in range(p,r):
		if A[j]<=A[r] :
			y=A[j]
			A[j]=A[i]
			A[i]=y
			i=i+1
	y=A[i]
	A[i]=A[r]
	A[r]=y
	return (i) 
	
def quickSort_randompivot(A,p,r):
	start=time.time()
	if p<r :
		q=partition_randompivot(A,p,r) 
		quickSort_randompivot(A,p,q-1)
		quickSort_randompivot(A,q+1,r)
	end=time.time()
	return (A,end-start)
	
def display(arr):
	for i in range(20):
		print(arr[i], end=",")




l=int(input("\nEnter length of array "))
A= list()


for i in range(l):
	z=random.randint(1,10)
	A.append(z)

I= A.copy()
M= A.copy()
QE= A.copy()
QS= A.copy()
QR= A.copy()
	
ins=list()

ins,ti=insertion(I,l)	

ms=list()

ms,tm=mergeSort(M,0,l-1) 


S = [ut for  ut in range(0, 5000)]
print("\n dwer----",A[0:20])
print("\n -----",S[0:20])

qs_end=list()
qs_end,tq=quickSort_endpivot(QE,0,l-1,S) 

qs_start=list()
qs_start,tqs=quickSort_startpivot(QS,0,l-1) 


qs_random=list()
qs_random,tqr=quickSort_randompivot(QR,0,l-1)

print("\n\nFirst 20 Sorted elements using INSERTION sort : ")
display(ins)
print("\nTime taken for sorting ",l," elements : ", ti)

print("\n\nFirst 20 Sorted elements using MERGE sort : ")
display(ms)
print("\nTime taken for sorting ",l," elements : ", tm)


print("\n\nFirst 20 Sorted elements using QUICK sort (LAST element as Pivot) : ")
display(qs_end)

print("\n -----",S[0:20],"\n-----/n")
print("\nTime taken for sorting ",l," elements : ", tq)

print("\n\nFirst 20 Sorted elements using QUICK sort (START element as Pivot) : ")
display(qs_start)
print("\nTime taken for sorting ",l," elements : ", tqs)

print("\n\nFirst 20 Sorted elements using QUICK sort (RANDOM element as Pivot) : ")
display(qs_random)
print("\nTime taken for sorting ",l," elements : ", tqr)











		

#include<iostream>
using namespace std;




void subset_sum_count(int arr[], int sum, int n){
	int t[n+1][sum+1];

	for (int i = 0; i < sum+1; ++i)
	{
		t[0][i]=false;
	}

	for (int i = 0; i < n+1; ++i)
	{
		t[i][0]=true;
	}

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < sum+1; ++j)
		{
			t[i][j]=0;
		}
	}

	cout<<"Before DP"<<endl;
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < sum+1; ++j)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < sum+1; ++j)
		{
			if(arr[i-1]<=j){
				t[i][j]=t[i-1][j-arr[i-1]] + t[i-1][j];
			}

			else{
				t[i][j]=t[i-1][j];
			}
		}
	}

	cout<<"After DP"<<endl;

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < sum+1; ++j)
		{
			cout<<t[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<t[n][sum];
	return;
}

void target_Sum(int arr[], int n, int sum){
	int s1,arr_sum=0;
	for (int i = 0; i < n; ++i)
	{
		arr_sum=arr_sum+arr[i];
	}
	s1=(arr_sum+sum)/2;
	subset_sum_count(arr,s1,n);
	return;
}


int main(){
	int arr[]={1,1,2,3};
	int sum=1;
	int n=sizeof(arr)/sizeof(arr[0]);
	target_Sum(arr, n, sum);

}
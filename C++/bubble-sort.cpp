#include <bits/stdc++.h>

using namespace std;

// Simple implementation of bubble sort.

void bubble_sort(vector < int > &v){
	const int N = v.size();
	for(int i = 0;i < N;++i){
		for(int j = 0;j < N-i-1;++j){
			if(v[j] > v[j+1]){
				const int tmp = v[j+1];
				v[j+1] = v[j];
				v[j] = tmp;
			}
		}
	}
}

// Demonstration of the algorithm working.

int main(){
	int n;
	cin >> n;
	vector < int > v(n);
	srand(time(0));
	for(int i = 0;i < n;++i){
		v[i] = rand()%1024;
	}
	bubble_sort(v);
	for(auto i : v)
		cout << i << " ";
	cout << endl;
}
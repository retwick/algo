//implement BIT to get prefix sum and get time plot

#include <bits/stdc++.h>
using namespace std;

void printBIT(int arr[], int n){
    for(int i = 1 ; i <= n ; ++i){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void updateBIT(int BIT[], int n, int index, int val){
	index = index +1;

	while(index <= n){
		BIT[index] += val;
		index += index & (-index);
	}
}

int getSum(int BIT[], int index){
	int sum = 0;
	index ++;
	while(index > 0){
		sum += BIT[index];
		index -=  index & (-index);
	}
	return sum;
}

int* createBIT(int arr[], int n){
	int i;
	int * BIT = (int*) malloc(sizeof(int)*(n+1));
	for (i = 0; i < n+1; ++i){
		BIT[i] = 0;
	}

	for(int index = 0; index < n; ++index){
		int val = arr[index];
		int i = index + 1;
		while(i <= n){
			BIT[i] += val;
			i += i & (-i);
		}
		//updateBIT(BIT,n,index,arr[index]);				
		//printBIT(BIT,n);
	}
	return BIT;
}




int main(int argc, char const *argv[])
{
	int freq[] = {1,7,3,0,5,8,3,2,6,2,1,1,4,5};
	int n = sizeof(freq)/sizeof(freq[0]);
	int *BIT = createBIT(freq,n);
	//printBIT(BIT,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<getSum(BIT,i)<<endl;
	}
	
	return 0;
}
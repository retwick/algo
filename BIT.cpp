//implement BIT to get prefix sum and get time plot

#include <bits/stdc++.h>
using namespace std;

template <typename T, typename N>
void printBIT(T arr[], N n){
    for(N i = 1 ; i <= n ; ++i){
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template <typename T, typename N>
void updateBIT(T BIT[], N n, N index, N val){
	index = index +1;

	while(index <= n){
		BIT[index] += val;
		index += index & (-index);
	}
}

template <typename T, typename N>
T* createBIT(T arr[], N n){
	N i;
	T * BIT = (int*) malloc(sizeof(T)*(n+1));
	for (i = 0; i < n+1; ++i){
		BIT[i] = 0;
	}

	for(N index = 0; index < n; ++index){
		T val = arr[index];
		N i = index + 1;
		while(i <= n){
			BIT[i] += val;
			i += i & (-i);
		}
	}
	return BIT;
}

template <typename T, typename N>
N getSum(T BIT[], N index){
	N sum = 0;
	index ++;
	while(index > 0){
		sum += BIT[index];
		index -=  index & (-index);
	}
	return sum;
}

/*
driver program
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
*/
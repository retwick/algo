#include "BIT.cpp"

int* createTree(int init, int size){
	int* BIT = (int*) malloc(sizeof(int)*(size+1));

	for (int i = 1; i <= size; ++i)	{
		BIT[i] = 0;
	}
	return BIT;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	//int arr[] = {1,7,3,0,5,8,3,2,6,2,1,1,4,5};
	//int n = sizeof(freq)/sizeof(freq[0]);

	int max = arr[0];
	for (int i = 0; i < n; ++i){
		if(max < arr[i])
			max = arr[i];
	}

	int *BIT = createTree(0,max);
	int inversionCount = 0;
	for (int i = n-1; i>= 0 ; --i){
		inversionCount += getSum<int,int>(BIT,arr[i]-1);
		updateBIT<int,int>(BIT, max, arr[i] - 1, 1);
	}
	cout<<inversionCount;
	return 0;
}
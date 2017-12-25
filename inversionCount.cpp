//count inversions using merge sort
//recursive approach
//Time Complexity O(nlogn)
//Space Complexity O(n)

#include <bits/stdc++.h>
using namespace std;

int getInv(int[], int, int, int[]);
int merge(int[], int, int, int[]);
int countInversion(int[], int);


// #inv = #inv on left part + #inv on right part + #inv on merge
int getInv(int a[],int l, int r, int temp[]){
	if(l < r)
		return getInv(a, l, (l+r)/2, temp) + getInv(a, (l+r)/2+1, r, temp) + merge(a,l,r,temp);
	return 0;
}


//left and right are sorted.
//O(n)
int merge(int a[],int l,int r, int temp[]){
	int i = l,j ,k = 0, inversions = 0;
	int mid = (l+r)/2;
	j = mid + 1;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]){
			temp[k] = a[i];
			++k;
			++i;
		}
		else{
			temp[k] = a[j];
			++k;
			++j;
			inversions += mid - i + 1;
		}
	}
	while(i <= mid){
		temp[k] = a[i];
		++k,++i;
	}
	while(j <= r){
		temp[k] = a[j];
		++k,++j;
	}
	k = 0;
	for(i = l; i <=r; ++i){
		a[i] = temp[k];
		++k;
	}
	return inversions;
}

int countInversion(int a[], int n){
	int *temp = (int*)malloc(sizeof(int)*n);
	return getInv(a,0,n-1,temp);
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n ; ++i){
        cin>>a[i];
    }
    
	cout<<countInversion(a,n)<<endl;
	
	return 0;
}
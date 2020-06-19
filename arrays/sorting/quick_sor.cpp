#include<bits/stdc++.h>
using namespace std;

int partitiona_arr(int arr[], int low, int high){
	int pivot = arr[low];
	int i = low, j = high;
	while(i < j){
		do{
			i++;
		}while(arr[i] <= pivot);
		do{
			j--;
		}while(arr[j] > pivot);
		if(i < j){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	return j;	
}

void quick_sort(int arr[], int low, int high){
	if(low < high){
		int new_pivot_pos = partitiona_arr(arr, low, high);
		quick_sort(arr, low, new_pivot_pos);
		quick_sort(arr, new_pivot_pos+1, high);
	}
}

int main(){
	int n; cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	quick_sort(arr, 0, n);
	
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
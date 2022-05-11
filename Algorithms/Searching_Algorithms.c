#include <stdio.h>

int linearsearch(int arr[], int size, int element){
	for (int i = 0 ; i < size ; i++){
		iff (arr[i] == element){
			return i;
		}
	}
	return -1; 
}



int binarysearch(int arr[], int size, int element){
	int low, mid, high;
	int low = 0;
	int high = size - 1;
	while (low <= high ){
		mid = (low + high) / 2;
		if (arr[mid] == element){
			return mid;
		}
		else if (arr[mid] < element){
			low = mid + 1;
		}
		else if (arr[mid] > element){
			high = mid - 1;
		}
	}
	return -1;
}
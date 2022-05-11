#include <stdio.h>

void display(int arr[], int size){
	// Code For traversal
	for (int i = 0; i < size ; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

int insertion(int arr[], int size, int element, int capacity, int index){
	if (size >= capacity){
		return -1;
	} else {
		for (int i = size - 1; i >= index ; i--){
			arr[i+1] = arr[i];
		}
		arr[index] = element;
		return 1;
	}
}

void deletion(int arr[], int size, int index){
	for (int i = index; i < size - 1; i++){
		arr[i] = arr[i+1];
		// Dont care about the last elemenet
	}
	return;
}

void search (int arr[], int size, int element){
	for (int i = 0; i < size; i++){
		if (arr[i] == element){
			printf("Element found at position : %d\n", i+1);
		} else {
			printf("Element Not Found");
		}
	}
	return;
}


int main(void){
	int x = 1;
	int choice;
	int arr[100] = {7, 5, 34, 56, 86, 2};
	int size = 6;
	do{
		printf("Select 1 for Insertion, 2 for deletion, 3 for search, 4 for display and 0 to quit ");
		scanf("%d", &choice);

		if (choice == 1){
			int element = 12;
			int index = 4;
			insertion(arr, size, element, 100, index);
			// Increase the size after addition for other operations
			size +=1 ;
		} else if (choice == 2){
			int index = 3;
			deletion(arr, size, index);
			size -= 1;
		} else if (choice == 3){
			int element = 86;
			search(arr, size, element);
		} else if (choice == 4){
			display(arr, size);
		} else if (choice == 0){
			x = 0;
		}
	} while (x == 1);

	return 0;
}
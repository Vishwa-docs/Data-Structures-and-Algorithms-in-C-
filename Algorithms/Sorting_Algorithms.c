#include <stdio.h>
#include <stdlib.h>

void Display(int * A, int n){
	for (int i = 0; i < n; i++){
		printf("%d ", A[i]);
	}
	printf("\n")
}

void bubbleSort(int * A, int n){
	int temp;
	int isSorted 0;
	for (int i = 0 ; i < n - 1; i++){
		printf("Pass number : %d\n", i + 1);
		for (int j = 0; j < n - 1 - i; j++){
			if (A[j] > A[j + 1]){
				temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}


void insertionSort(int * A, int n){
	int key, j;
	for (int i = 1; i <= n - 1; i++){
		key = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > key){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}


void selectionSort(int * A, int n){
	int indexOfMin, temp;
	for (int i = 0; i < n - 1; i++){
		indexOfMin = i;
		for (int j = i + 1; j < n; j++){
			if (A[j] < A[indexOfMin]){
				indexOfMin = j;
			}
		}

		// Swap elemenets
		temp = A[i];
		A[i] = A[indexOfMin];
		A[indexOfMin] = temp;
	}
}


// Quick Sort
int partition(int A[], int low, int high){
	int pivot = A[low];
	int i = low + 1;
	int j = high;
	int temp;

	do {
		while (A[i] <= pivot){
			i++;
		}

		while (A[j] > pivot){
			j--;
		}

		if (i < j){
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	} while (i < j);

	temp = A[low];
	A[low] = A[j];
	A[j] = temp;
	return j;
}

void quickSort(int A[], int low, int high){
	int partitionIndex; // Index of pivot after partition

	if (low < high){
		partitionIndex = partition(A, low, high);
		quickSort(A, low, partitionIndex - 1); // Sort left subarray
		quickSort(A, partitionIndex + 1, high); // Sort right subarray
	}
}


// Merge Sort 
void merge(int A[], int mid, int low, int high){
	int i, j, k, B[100];

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high){
		if (A[i] < A[j]){
			B[k] = A[i];
			i++;
			k++;
		} else {
			B[k] = A[j];
			j++;
			k++;
		}
	}

	while (i <= mid){
		B[k] = A[i];
		k++;
		i++;
	}

	while (i <= mid){
		B[k] = A[i];
		k++;
		i++;
	}

	while (j <= high){
		B[k] = A[j];
		k++;
		j++;
	}

	for (int i = low; i<= high; i++){
		A[i] = B[i];
	}
}

void mergeSort(int A[], it low, int high){
	int mid;
	if (low < high){
		mid = (low + high) / 2;
		mergeSort(A, low, mid);
		mergeSort(A, mid+1, high);
		merge(A, mid, low, high);
	}
}


// Count Sort :
int maximum(int A[], int n){
	int max = 0;
	for (int i = 0; i < n; i++){
		if (max < A[i]){
			max = A[i];
		}
	}
	return max;
}


void CountSort(int * A; int n){
	int i, j;

	// Find the maximum element in A
	int max = maximum(A, n);

	// Create the count array
	int * count = (int *) malloc ((max + 1) * sizeof(int));

	// Initialize all the elements to 0
	for (int i = 0; i < max + 1; i++){
		count[i] = 0;
	}

	// Increment the corresponding index in the count of the array
	for (int i = 0; i < n; i++){
		count[A[i]] = count[A[i]] + 1;
	}

	i = 0; // Counter for count array
	j = 0; // Counter for given array A

	while (i <= max){
		if (count[i] > 0){
			A[j] = i;
			count[i] = count[i] - 1;
			j++;
		} else {
			i++;
		}
	}
}

// Shell Sort
void ShellSort(int A[], int n){
	// Start with a gap of n/2 (big) then reduce by taking floor of dividing by 2
	for (int gap = n/2; gap > 0; gap /= 2){
		/*
		Do a gap insertion sort. The first gap elements a[0 to gap - 1] are already in gapped order.
		Keep adding one more element until the entire array is gap sorted
		*/

		for (int i = gap; i < n; i++){
			/*
			Add a[i] to the elements that have been gap sorted
			Save a[i] in temp and make a hole at position i
			*/

			int temp = A[i];
			// Shift earlier elements up until the correct location for A[i] is found

			int j;
			for (j = i; j >= gap && A[j - gap] > temp; j -= gap){
				A[j] = A[j - gap];
			}

			// Put the original A[i] in its correct location
			A[j] = temp;
		}
	}
} // Here time complexity is O(n^2)
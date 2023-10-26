#include<iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}
void insertionSort(int arr[], int size) {

	int temp = 0;
	for (int i = 0; i < size-1; i++) {
		for (int j = i; j >= 0; j--) {
			if (arr[j + 1] < arr[j]) {

				//swap the numbers
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;

			}
		}
	}
}




int main(){

	int arr[] = { 64,25,12,22,11 };
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 5,4,3,2,1 };
	int arr3[] = { 6,3,2,7,1,8,0,1 };
	//Find length of array
	int size1 = sizeof(arr) / sizeof(arr[0]);
	int size2 = sizeof(arr1) / sizeof(arr1[0]);
	int size3 = sizeof(arr2) / sizeof(arr2[0]);
	int size4 = sizeof(arr3) / sizeof(arr3[0]);

	insertionSort(arr, size1);
	insertionSort(arr2, size2);
	insertionSort(arr3, size3);
	insertionSort(arr1, size1);
	cout << "Sorted array: \n";
	printArray(arr3, size3);

	cout << endl;
	printArray(arr2, size2);

	cout << endl;
	printArray(arr1, size1);

	cout << endl;
	printArray(arr, size1);


	return 0;
}
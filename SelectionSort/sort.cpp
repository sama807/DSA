#include<iostream>
using namespace std;

void selectionSort(int arr[], int size) {

	int minElement = 0, j=0, index=0;
	minElement = arr[0];
	for (int i = 0; i < size-1; i++) {
		for (j = i + 1; j < size; j++) {

			//find the minimum number
			if (minElement > arr[j]) {
				minElement = arr[j];
				index = j;
				
			}
			
		}
		//swap the numbers
		//if index==0 it means array is already sorted
		if (index != i && index!=0) {
			arr[index] = arr[i];
			arr[i] = minElement;
		}
		index = 0;
		minElement = arr[i + 1];


		
		
	}
}


// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{
	int arr[] = { 64,25,12,22,11 };
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 5,4,3,2,1 };
	int arr3[] = { 6,3,2,7,1,8,0,1};
	//Find length of array
	int size1 = sizeof(arr) / sizeof(arr[0]);
	int size2 = sizeof(arr1) / sizeof(arr1[0]);
	int size3 = sizeof(arr2) / sizeof(arr2[0]);
	int size4 = sizeof(arr3) / sizeof(arr3[0]);

	selectionSort(arr, size1);
	selectionSort(arr2, size2);
	selectionSort(arr3, size3);
	selectionSort(arr1, size1);
	cout << "Sorted array: \n";
	printArray(arr3, size3);

	cout << endl;
	printArray(arr2, size2);

	cout <<endl;
	printArray(arr1, size1);

	cout <<endl;
	printArray(arr, size1);




}
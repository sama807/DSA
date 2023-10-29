#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key) {

	while (low <= high) {

		int mid = low + (high - low) / 2;
		// If the element is present at the middle
		if (arr[mid] == key)
			return mid;

		// If key greater, go to right half
		if (arr[mid] < key)
			low = mid + 1;

		// If key less, go to left half
		else
			high = mid - 1;


	}
	return -1;
}
int main() {

	int x = 1;
	int arr[] = { 1, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;

}
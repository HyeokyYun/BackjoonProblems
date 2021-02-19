#include <iostream>

using namespace std;

#define MAX 1000

int arr[MAX];
int partition(int *arr, int left, int right);

void quickSort(int arr[], int left, int right){
	int index;

	if(left < right){
		index = partition(arr, left, right);

		quickSort(arr, left, index - 1);
		quickSort(arr, index + 1, right);
	}
	else
		return;
}

int partition(int arr[], int left, int right){
	int pivot = arr[right];
	int i;
	int index = left - 1;

	int temp;

	for(i = left; i < right; i++){
		if(arr[i] <= pivot){
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;
		}
	}

	temp = arr[index];
	arr[index] = arr[right];
	arr[right] = temp;
	return index + 1;
}

int main() {
  int n;

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	quickSort(arr, 0, n-1);

	for(int i = 0; i < n; i++)
		cout << arr[i] << endl;
}

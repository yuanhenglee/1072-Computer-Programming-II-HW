#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *arr, int size){

	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		while (key < arr[j] && j >= 0) {
			arr[j+1] = arr[j];
			j--;

		}
		arr[j+1] = key;

	}

}
void PrintArray(int *arr, int size){
	for (int i = 0; i < size; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main() {
	
	int num = rand()%30+5;
	int *array = calloc(num,sizeof(int));
	for( int i =0 ; i < num ; ++i )
		array[i] = rand()%num+1;
	printf("original:\n");
	PrintArray(array, num);

	InsertionSort(array, num);

	printf("sorted:\n");
	PrintArray(array, num);
	return 0;

}

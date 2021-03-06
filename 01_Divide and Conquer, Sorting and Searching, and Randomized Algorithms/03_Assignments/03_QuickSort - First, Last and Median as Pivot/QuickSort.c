/*
	10,000 numbers in QuickSort.txt
	Use first number as the pivot. The comparisons is 162,085
	Use last number as the pivot. The comparisons is 164,123
	Use median of three as the pivot. The comparisons is 138,382
*/
#include <stdio.h>
void swap(int *a, int *b){
  	int tmp = *a;
  	*a = *b;
  	*b = tmp;  
}

int partition(int array[], int left, int right, int pivotIndex, int *counter){
	int pivotValue = array[pivotIndex], compareIndex = left + 1;
	swap(&array[left], &array[pivotIndex]);
	*counter += right - left;
	for(int i = left + 1; i <= right; i++)
		if(array[i] < pivotValue){
			swap(&array[compareIndex], &array[i]);
			compareIndex++;
		}
	swap(&array[--compareIndex], &array[left]);
	return compareIndex;
}

int medianOfThree(int array[], int left, int right){
	int length = right - left + 1;
	int mid = (length % 2) == 0 ? ((length / 2) - 1) + left : (length / 2) + left;
	int first = array[left], middle = array[mid], last = array[right];
	if ((middle < first && first < last) || (middle > first && first > last))
    	return left;
	if ((first < middle && middle < last) || (first > middle && middle > last))
		return mid;
	return right;
}
void quickSort(int array[], int left, int right, int *counter){
	if(right > left){
		int newPivotIndex = partition(array, left, right, medianOfThree(array, left, right), counter);
		quickSort(array, left, newPivotIndex - 1, counter);
		quickSort(array, newPivotIndex + 1, right, counter);
	}
}

void main(void){
	FILE *inFile, *wFile;
	int size = 10000;
	int inputArray[size];
	int i = 0, counter = 0;
	int *counterPtr;
	counterPtr = &counter;
	inFile = fopen("QuickSort.txt", "r");
	wFile = fopen("sorted.txt", "w");
	if(!inFile)
		printf("Fail to open file\n");
	else
		printf("Open file successfully!\n");
	for(i = 0; i < size; i++)
		fscanf(inFile, "%d", &inputArray[i]);
	quickSort(inputArray, 0, size - 1, counterPtr);
	for(i = 0; i < size - 1; i++)
		fprintf(wFile, "%d\n", inputArray[i]);
	fprintf(wFile, "%d", inputArray[size - 1]);
	printf("Comparison counts = %d\n", counter);
	fclose (inFile);
	fclose (wFile);
}
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//两个有序数组的合并
void merge(int* array, int begin, int mid, int end,int* tmp) {
	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 <= end2) {
		if (array[begin1] <= array[begin2])
			tmp[idx++] = array[begin1++];
		else
			tmp[idx++] = array[begin2++];
	}
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, array + begin2, sizeof(int)*(end2 - begin2 + 1));
	memcpy(array+begin, tmp+begin, sizeof(int)*(end - begin + 1));
}

void mergeSortR(int* array, int begin, int end,int* tmp) {
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSortR(array, begin, mid,tmp);
	mergeSortR(array, mid + 1, end,tmp);
	merge(array, begin, mid , end,tmp);
}

void mergeSort(int* array, int n) {
	int* tmp = (int*)malloc(sizeof(int)*n);
	mergeSortR(array, 0, n - 1, tmp);
	free(tmp);
}
//直接插入排序
void inserSort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int key = array[end + 1];
		while (end >= 0 && array[end] > key) {
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
void Swap(int* array, int begin, int end) {
	int tmp = array[begin];
	array[begin] = array[end];
	array[end] = tmp;
}
//冒泡排序:往后冒
void bubbleSort(int* array, int n) {
	while (n) {
		int flag = 0;
		for (int i = 0; i < n - 1; i++) {
			if (array[i + 1] < array[i]) {
				Swap(array, i + 1, i);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void shiftDown(int* array, int n, int parent) {
	int child = 2 * parent + 1;
	while (child < n) {
		if(child + 1 < n && array[child] < array[child + 1])
			child++;
		if (array[child] > array[parent]) {
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void heapSort(int* array, int n) {
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(array, n, i);
	}
	while (n) {
		Swap(array, 0, n - 1);
		n--;
		shiftDown(array, n, 0);
	}
}

void selectSort(int* array, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		int start = min;
		for (int j = i + 1; j < n; j++) {
			if (array[j] < array[min])
				min = j;
		}
		Swap(array, start, min);
	}
}

int main() {
	int array[] = { 10,9,8,7,6,5,4,3,2,1 };
	int size = sizeof(array) / sizeof(array[0]);
	//mergeSort(array, size);
	//inserSort(array, size);
	//bubbleSort(array, size);
	//heapSort(array, size);
	selectSort(array, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

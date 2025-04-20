#include<stdio.h>
#include <conio.h>

void swap(int* a, int* b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}

int partition(int *arr, int low, int high){
 int pivot = arr[high];
 int i = low - 1;
 int j;

 for (j = low; j <= high - 1; j++) {
  if (arr[j] < pivot) {
   i++;
   swap(&arr[i], &arr[j]);
  }
 }

 swap(&arr[i + 1], &arr[high]);
 return i + 1;
}

void quicksort(int arr[], int low, int high) {
 if (low < high) {
  int pi = partition(arr, low, high);

  quicksort(arr, low, pi - 1);
  quicksort(arr, pi + 1, high);
 }
}

int *getArr(int size) {
 int *arr = (int *)malloc(sizeof(int) * size);
 int i, temp;
 for (i = 0; i < size; i++) {
  printf("%d'th element: ", i + 1);
  scanf("%d", &temp);
  arr[i] = temp;
 }

 return arr;
}

int getSize() {
 int size;

 clrscr();

 printf("Enter size of the array: ");
 scanf("%d", &size);

 return size;
}


int main() {
 int n = getSize();
 int *arr = getArr(n);
 int i;

 quicksort(arr, 0, n - 1);

 for (i = 0; i < n; i++) {
  printf(" %d ", arr[i]);
 }

 getch();
 return 0;
}

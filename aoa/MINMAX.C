#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void minmax(int *arr, int size) {
 int min = arr[0], max = arr[0], i;

 for (i = 1; i < size; i++) {
  if (arr[i] > max) {
   max = arr[i];
  }

  if (arr[i] < min) {
   min = arr[i];
  }
 }

 printf("Maximum: %d, Minimum: %d", max, min);
}

void display(int *arr, int size) {
 int i;

 for (i = 0; i < size; i++) {
  printf(" %d ", arr[i]);
 }

 printf("\n");
}

int *input(int size) {
 int *arr = (int *)malloc(sizeof(int) * size);
 int i, temp;

 for (i = 0; i < size; i++) {
  printf("Enter %d'th element: ", i + 1);
  scanf("%d", &temp);
  arr[i] = temp;
 }

 return arr;
}

int size() {
 int sz;
 clrscr();
 printf("Enter size of array: ");
 scanf("%d", &sz);
 return sz;
}


int main() {
 int sz = size();
 int *arr = input(sz);
 display(arr, sz);
 minmax(arr, sz);

 getch();
 return 0;
}

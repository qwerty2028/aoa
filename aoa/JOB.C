#include <stdio.h>
#include <conio.h>

void display(int *, int);

void bubbleSortDescending(int profit[], int job[], int n) {
    int i, j, tempProfit, tempJob;
    for (i = 0; i < n-1; i++) {
	for (j = 0; j < n-i-1; j++) {
	    if (profit[j] < profit[j+1]) {
		tempProfit = profit[j];
		profit[j] = profit[j+1];
		profit[j+1] = tempProfit;

		tempJob = job[j];
		job[j] = job[j+1];
		job[j+1] = tempJob;
	    }
	}
    }
}

int searchEmpty(int *arr, int deadline) {
 int i = 0;
 for (i = deadline - 1; i >= 0; i--) {
  if (arr[i] == 0) {
   return i;
  }
 }

 return -1;
}

void jobseq(int *profit, int *job, int *final, int size) {
 int i = 0, profitFinal = 0;
 for (i = 0; i < size; i++) {
  int pro = profit[i];
  int jo =  job[i];
  int search = searchEmpty(final, jo);

  if (search != -1) {
   final[search] = i + 1;
   profitFinal += pro;
  }
 }
 printf("\nOptimal sequence: ");
 display(final, size);
 printf("\nProfit: %d", profitFinal);
}

void display(int *arr, int size) {
 int i = 0;
 printf("\n");

 for (i = 0; i < size; i++) {
  if (arr[i] != 0) {
  printf("P%d ", arr[i]);
  }
 }

 printf("\n");
}

int sizeI() {
 int size;
 clrscr();
 printf("Enter the number of jobs: ");
 scanf("%d", &size);
 return size;
}

void inputs(int *profit, int *job, int size) {
 int i = 0;
 int tempP, tempD;
 for (i = 0; i < size; i++) {
  printf("Enter the profits and deadline for J%d: ", i + 1);
  scanf(" %d %d", &tempP, &tempD);
  job[i] = tempD;
  profit[i] = tempP;
 }
}

int main() {
 int size = sizeI(), i = 0;
 int *profit = (int *)malloc(sizeof(int) * size);
 int *job = (int *)malloc(sizeof(int) * size);
 int *final = (int *)malloc(sizeof(int) * size);

 for (i = 0; i < size; i++) {
  final[i] = 0;
 }

 inputs(profit, job, size);
 bubbleSortDescending(profit, job, size);
 jobseq(profit, job, final, size);

 getch();
 return 0;
}
#include <stdio.h>
#include <conio.h>

void selsort(int arr[], int n) {
    int i, j, small, temp;
    for (i = 0; i < n - 1; i++) {
        small = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[small]) {
                small = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

void display(int arr[], int n) {
    int i;
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n,i;
    int arr[100];
    printf("Enter the number of elements: ");
    scanf("%d", &n);


    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selsort(arr, n);
    display(arr, n);

    getch();
    return 0;
}

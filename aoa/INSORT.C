#include <stdio.h>

int main() {
    int i, j, n, key;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}

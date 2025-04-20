#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int compare(const void *a, const void *b) {
    struct Item *item1, *item2;
    item1 = (struct Item *)a;
    item2 = (struct Item *)b;
    
    if (item2->ratio > item1->ratio) 
        return 1;
    if (item2->ratio < item1->ratio) 
        return -1;
    return 0;
}

float fractionalKnapsack(int capacity, struct Item *items, int n) {
    int i, remainingCapacity;
    float totalProfit;

    qsort(items, n, sizeof(items[0]), compare);
    totalProfit = 0.0;
    remainingCapacity = capacity;
    
    for (i = 0; i < n; i++) {
        if (remainingCapacity == 0) 
            break;
        if (items[i].weight <= remainingCapacity) {
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        } else {
            totalProfit += items[i].profit * ((float)remainingCapacity / items[i].weight);
            remainingCapacity = 0;
        }
    }
    return totalProfit;
}

int main() {
    int n, capacity, i;
    float maxProfit;
    struct Item *items;

    clrscr();  

    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    items = (struct Item*) malloc(n * sizeof(struct Item));

    if (items == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter the profit and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    maxProfit = fractionalKnapsack(capacity, items, n);
    printf("Maximum profit that can be obtained: %.2f\n", maxProfit);

    free(items);  

    getch();  
    return 0;
}

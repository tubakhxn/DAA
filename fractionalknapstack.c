#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct Item {
    int weight;
    int value;
};
int compare(const void *a, const void *b) {
    double ratioA = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double ratioB = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    if (ratioA > ratioB) return -1;
    if (ratioA < ratioB) return 1;
    return 0;
}
double fractional_knapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(struct Item), compare);

    double total_value = 0.0;
    int current_weight = 0;

    for (int i = 0; i < n; i++) {
        if (current_weight + items[i].weight <= capacity) {
            total_value += items[i].value;
            current_weight += items[i].weight;
        } else {
            int remaining_capacity = capacity - current_weight;
            total_value += (double)remaining_capacity / items[i].weight * items[i].value;
            break;
        }
    }

    return total_value;
}

int main() {
    clock_t start,end;
    double cpu_time_used;
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Weight = ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d: Value = ", i + 1);
        scanf("%d", &items[i].value);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    double max_value = fractional_knapsack(items, n, capacity);
    printf("Maximum value: %.2f\n", max_value);
    end = clock(); 
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);

    return 0;
}
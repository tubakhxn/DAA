#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct Activity {
    int start;
    int finish;
};
int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}
void activitySelection(struct Activity activities[], int n) {
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("Selected Activities: \n");
    int i = 0;
    printf("Activity %d: Start time = %d, Finish time = %d\n", i + 1, activities[i].start, activities[i].finish);
    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d: Start time = %d, Finish time = %d\n", j + 1, activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activities[n];

    printf("Enter the start and finish times of each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: Start time = ", i + 1);
        scanf("%d", &activities[i].start);
        printf("Activity %d: Finish time = ", i + 1);
        scanf("%d", &activities[i].finish);
    }

    activitySelection(activities, n);
    end = clock(); 
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
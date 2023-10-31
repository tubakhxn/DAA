#include <stdio.h>

int main() {
    int n, searchKey;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search for: ");
    scanf("%d", &searchKey);

    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == searchKey) {
            printf("Element %d found at index %d\n", searchKey, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array\n", searchKey);
    }

    return 0;
}

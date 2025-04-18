#include <stdio.h>
#include <time.h>
#include <conio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[100], right[100];
    int i, j, k;
    
    for (i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        right[j] = arr[m + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r) {
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void display(int arr[], int size) {
    int i;
    printf("\nArray: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;
    int arr[100];
    clock_t start, end;
    double time_taken;
    
    clrscr();
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sorting:");
    display(arr, n);

    start = clock();
    mergesort(arr, 0, n - 1);
    end = clock();

    printf("After sorting:");
    display(arr, n);

    time_taken = ((double)(end - start)) / CLK_TCK;
    printf("\nTime taken: %lf seconds\n", time_taken);

    getch();
    return 0;
}

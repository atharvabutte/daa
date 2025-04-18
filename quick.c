#include <stdio.h>
#include <time.h>
#include <conio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int temp;
    int i = low + 1;
    int j = high;
    
    do {
        while (i <= high && a[i] < pivot)
            i++;
        while (j >= low && a[j] > pivot)
            j--;
            
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p_index = partition(arr, low, high);
        quicksort(arr, low, p_index - 1);
        quicksort(arr, p_index + 1, high);
    }
}

int main() {
    int n;
    int arr[100];
    clock_t start, end;
    double time_taken;

    clrscr();
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Before sorting: ");
    display(arr, n);

    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();

    printf("After sorting: ");
    display(arr, n);

    time_taken = ((double)(end - start)) / CLK_TCK;
    printf("Time taken: %f seconds\n", time_taken);

    getch();
    return 0;
}

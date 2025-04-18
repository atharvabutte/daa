#include <stdio.h>
#include <conio.h>

struct Item {
    int w, v;
    float ratio;
};

void fractionalk(struct Item item[], int capacity, int n) {
    int i, j;
    float totval;
    struct Item key;
    
    for (i = 0; i < n; i++) {
        item[i].ratio = (float) item[i].v / item[i].w;
    }
    
    for (i = 1; i < n; i++) {
        key = item[i];
        j = i - 1;
        
        while (j >= 0 && item[j].ratio < key.ratio) {
            item[j + 1] = item[j];
            j--;
        }
        item[j + 1] = key;
    }
    
    totval = 0.0;
    
    for (i = 0; i < n; i++) {
        key = item[i];
        if (capacity >= key.w) {
            totval += key.v;
            capacity -= key.w;
        } else {
            totval += capacity * key.ratio;
            break;
        }
    }
    
    printf("Maximum value in knapsack: %.2f\n", totval);
}

int main() {
    int n, capacity, i;
    struct Item item[100];
    
    clrscr();
    printf("Enter number of items: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &item[i].v, &item[i].w);
    }
    
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);
    
    fractionalk(item, capacity, n);
    
    getch();
    return 0;
}

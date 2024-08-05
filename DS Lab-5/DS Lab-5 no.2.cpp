// Write a program to generate the next r combination in lexicographic order.


#include <stdio.h>
#include <stdlib.h>


void print_combination(int* data, int r) {
    for (int i = 0; i < r; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}


void combination_util(int arr[], int n, int r, int index, int data[], int i) {
   
    if (index == r) {
        print_combination(data, r);
        return;
    }

   
    if (i >= n) {
        return;
    }

   
    data[index] = arr[i];
    combination_util(arr, n, r, index + 1, data, i + 1);

    
    combination_util(arr, n, r, index, data, i + 1);
}


int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


void print_combinations(int arr[], int n, int r) {
    
    qsort(arr, n, sizeof(int), compare);

  
    int* data = (int*)malloc(r * sizeof(int));

 
    combination_util(arr, n, r, 0, data, 0);

    free(data);
}

int main() {
    int arr[] = {1, 2, 3, 4}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int r;
    
    printf("Enter the range (r) :- ");
    scanf("%d",&r);

    print_combinations(arr, n, r);

    return 0;
}


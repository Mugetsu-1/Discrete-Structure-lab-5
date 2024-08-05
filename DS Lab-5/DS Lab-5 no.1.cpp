//Write a program to generate the next permutation in lexicographic order.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}


void reverse(char* str, int start, int end) {
    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}


int next_permutation(char* str) {
    int n = strlen(str);
    int i = n - 2;

 
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }

    
    if (i == -1) {
        return 0;
    }

   
    int j = n - 1;
    while (str[j] <= str[i]) {
        j--;
    }

    
    swap(&str[i], &str[j]);

   
    reverse(str, i + 1, n - 1);

    return 1;
}

void print_permutations(char* str) {
    
    qsort(str, strlen(str), sizeof(char), (int (*)(const void*, const void*)) strcmp);

    
    printf("%s\n", str);

    
    while (next_permutation(str)) {
        printf("%s\n", str);
    }
}

int main() {
    char str[] = "123"; // 
    print_permutations(str);
    return 0;
}


//Write a program to check whether a number is prime or not, with the help of Fermat’s little theorem.

#include <stdio.h>
#include <stdlib.h>


int power(int x, unsigned int y, int p) {
    int res = 1; 
    x = x % p;    

    while (y > 0) {
       
        if (y & 1)
            res = (res * x) % p;

        
        y = y >> 1;   
        x = (x * x) % p;  
    }
    return res;
}

// Function to check if a number is prime using Fermat's Little Theorem
int is_prime(int n, int k) {

    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;


    while (k > 0) {
        // Pick a random number in [2, n-2]
        int a = 2 + rand() % (n - 4);

        // Fermat's little theorem
        if (power(a, n - 1, n) != 1)
            return 0;

        k--;
    }

    return 1;
}

int main() {
    int n;  
    int k;  // Number of iterations
	
	printf("Enter the number :- ");
	scanf("%d",&n);
	printf("Enter the number of iterations :- ");
	scanf("%d",&k);
    if (is_prime(n, k))
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);

    return 0;
}


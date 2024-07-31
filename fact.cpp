#include <stdio.h>

int main() {
    int num;
    unsigned long long factorial = 1;

    // Input the number from the user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check for negative input
    if (num < 0) {
        printf("Factorial of a negative number is not defined.\n");
    } else {
        for(int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("fact of  %d is  %llu\n", num, factorial);
    }

    return 0;
}


#include <stdio.h>
int main() {
    float a, b, s, d;
    printf("Enter first number: ");
    scanf("%f, %f", &a, &b);
    s= a + b;
    d = a - b;
    printf("Sum: %.2f\n", s);
    printf("Difference: %.2f\n", d);

    return 0;
}


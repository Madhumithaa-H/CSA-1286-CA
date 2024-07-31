#include <stdio.h>
int main() {
    float a, b, s, d;
    printf("Enter first number: ");
    scanf("%f, %f", &a, &b);
    s= a*b;
    d = a/b;
    printf("mul: %.2f\n", s);
    printf("Div: %.2f\n", d);

    return 0;
}


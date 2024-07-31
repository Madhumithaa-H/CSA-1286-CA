#include <stdio.h>
#include <stdint.h>
#include <string.h>
void printDoubleBinary(double num) 
{
    uint64_t bits;
    memcpy(&bits, &num, sizeof(bits)); 
    for (int i = 63; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
        if (i % 4 == 0) printf(" "); 
    }
    printf("\n");
}

int main() 
{
    double num;
    printf("Enter a double-precision floating-point number: ");
    scanf("%lf", &num);
    printf("Binary representation of %.15lf:\n", num);
    printDoubleBinary(num);

    return 0;
}

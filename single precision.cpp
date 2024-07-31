#include <stdio.h>
#include <stdint.h>

// Define a union to interpret the bits of a float
typedef union {
    float value;
    struct {
        uint32_t mantissa : 23;
        uint32_t exponent : 8;
        uint32_t sign : 1;
    } parts;
    uint32_t bits;
} FloatBits;

// Function to print the binary representation of a 32-bit integer
void printBinary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    FloatBits fb;
    printf("Enter a single-precision floating-point number: ");
    scanf("%f", &fb.value);

    printf("\nFloat value: %f\n", fb.value);
    printf("Sign bit: %u\n", fb.parts.sign);
    printf("Exponent: %u (unbiased: %d)\n", fb.parts.exponent, fb.parts.exponent - 127);
    printf("Mantissa: %u\n", fb.parts.mantissa);

    printf("\nBinary representation:\n");
    printf("Sign bit: %u\n", fb.parts.sign);
    printf("Exponent: ");
    printBinary(fb.parts.exponent);
    printf("Mantissa: ");
    printBinary(fb.parts.mantissa);

    printf("\nFull binary representation:\n");
    printBinary(fb.bits);

    return 0;
}

#include <stdio.h>
#include <stdint.h>

// Define a union to interpret the bits of a double
typedef union {
    double value;
    struct {
        uint64_t mantissa : 52;
        uint64_t exponent : 11;
        uint64_t sign : 1;
    } parts;
    uint64_t bits;
} DoubleBits;

// Function to print the binary representation of a 64-bit integer
void printBinary(uint64_t num) {
    for (int i = 63; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    DoubleBits db;
    printf("Enter a double-precision floating-point number: ");
    scanf("%lf", &db.value);

    printf("\nDouble value: %lf\n", db.value);
    printf("Sign bit: %llu\n", db.parts.sign);
    printf("Exponent: %llu (unbiased: %lld)\n", db.parts.exponent, db.parts.exponent - 1023);
    printf("Mantissa: %llu\n", db.parts.mantissa);

    printf("\nBinary representation:\n");
    printf("Sign bit: %d\n", db.parts.sign);
    printf("Exponent: ");
    printBinary(db.parts.exponent);
    printf("Mantissa: ");
    printBinary(db.parts.mantissa);

    printf("\nFull binary representation:\n");
    printBinary(db.bits);

    return 0;
}

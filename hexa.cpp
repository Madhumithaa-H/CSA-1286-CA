#include <stdio.h>


void decimalToHexadecimal(int decimalNumber) {
    
    char hexDigits[] = "0123456789ABCDEF";
    char hexNumber[50];
    int index = 0;

    
    if (decimalNumber == 0) {
        printf("Hexadecimal: 0\n");
        return;
    }

    
    while (decimalNumber != 0) {
        int remainder = decimalNumber % 16;
        hexNumber[index++] = hexDigits[remainder];
        decimalNumber /= 16;
    }

    printf("Hexadecimal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", hexNumber[i]);
    }
    printf("\n");
}

int main() {
    int decimalNumber;

   
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

   
    decimalToHexadecimal(decimalNumber);

    return 0;
}

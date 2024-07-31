#include <stdio.h>
#include <math.h>


int binaryToDecimal(const char *binaryStr) {
    int decimal = 0;
    int length = 0;
    
    while (binaryStr[length] != '\0') {
        length++;
    }
    
    for (int i = 0; i < length; i++) {
        if (binaryStr[length - i - 1] == '1') {
            decimal += pow(2, i);
        }
    }
    
    return decimal;
}

void decimalToOctal(int decimalNumber) {
    char octalNumber[50];
    int index = 0;

    if (decimalNumber == 0) {
        printf("Octal: 0\n");
        return;
    }

    while (decimalNumber != 0) {
        octalNumber[index++] = (decimalNumber % 8) + '0';
        decimalNumber /= 8;
    }

    // Print the octal number in reverse order
    printf("Octal: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", octalNumber[i]);
    }
    printf("\n");
}

int main() {
    char binaryStr[50];
    
    printf("Enter a binary number: ");
    scanf("%s", binaryStr);

   
    int decimalNumber = binaryToDecimal(binaryStr);

   
    decimalToOctal(decimalNumber);

    return 0;
}

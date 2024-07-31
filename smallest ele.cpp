#include <stdio.h>

int main() {
    
    int numbers[] = {18, 45, 66, 23, 19, 10, 52, 71};
    int n = sizeof(numbers) / sizeof(numbers[0]); 
    int smallest = numbers[0]; 

    
    for (int i = 1; i < n; ++i) {
        if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

   
    printf("smallest no : %d\n", smallest);

    return 0;
}

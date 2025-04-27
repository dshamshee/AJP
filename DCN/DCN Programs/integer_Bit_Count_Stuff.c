#include <stdio.h>

// Function to count the number of set bits (1s) in an integer
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int num;
    printf("Enter an integer: ");
    
    // Check if the input is a valid integer
    if (scanf("%d", &num) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Exit the program with an error code
    }
    
    // Handle negative numbers by converting them to their unsigned equivalent
    unsigned int unsignedNum = (unsigned int)num;
    
    int result = countSetBits(unsignedNum);
    printf("Number of set bits in %d: %d\n", num, result);
    
    return 0;
}

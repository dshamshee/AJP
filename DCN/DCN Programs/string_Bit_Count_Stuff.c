#include <stdio.h>
#include <string.h>

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
    char input[100]; // Buffer to store the input string
    printf("Enter a string: ");
    
    // Read the input string
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1; // Exit the program with an error code
    }
    
    // Remove the newline character from the input (if present)
    input[strcspn(input, "\n")] = '\0';
    
    int totalSetBits = 0;
    
    // Iterate through each character in the string
    for (int i = 0; input[i] != '\0'; i++) {
        // Count the set bits in the ASCII value of the character
        totalSetBits += countSetBits((int)input[i]);
    }
    
    printf("Total number of set bits in the string: %d\n", totalSetBits);
    
    return 0;
}

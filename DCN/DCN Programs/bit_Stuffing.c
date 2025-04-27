/*
Enter the data (binary string): 111111
Data after bit stuffing: 1111101
*/

#include <stdio.h>
#include <string.h>

#define MAX_DATA_SIZE 100
#define MAX_STUFFED_SIZE 200

int main() {
    char data[MAX_DATA_SIZE], stuffedData[MAX_STUFFED_SIZE];
    int i, count = 0, j = 0;
    
    // Input the data
    printf("Enter the data (binary string): ");
    scanf("%s", data);
    
    // Validate the input data
    for (i = 0; i < strlen(data); i++) {
        if (data[i] != '0' && data[i] != '1') {
            printf("Invalid input. Please enter a binary string (only 0s and 1s).\n");
            return 1;
        }
    }
    
    // Perform bit stuffing
    for (i = 0; i < strlen(data); i++) {
        if (data[i] == '1') {
            count++;
            stuffedData[j++] = data[i];
        } else {
            count = 0;
            stuffedData[j++] = data[i];
        }
        
        if (count == 5) {
            count = 0;
            stuffedData[j++] = '0';
        }
    }
    
    stuffedData[j] = '\0'; // Null-terminate the stuffed data
    
    // Check if the stuffed data exceeds the buffer size
    if (j >= MAX_STUFFED_SIZE) {
        printf("Error: Stuffed data exceeds maximum size.\n");
        return 1;
    }
    
    // Output the stuffed data
    printf("Data after bit stuffing: %s\n", stuffedData);
    
    return 0;
}

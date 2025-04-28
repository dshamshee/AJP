#include<stdio.h>
#include<string.h>

// Define a maximum size for data and check value
#define MAX_LENGTH 50

// Declare arrays to store data and CRC check value
char data[MAX_LENGTH];
char check_value[MAX_LENGTH];
char gen_poly[MAX_LENGTH];

// Define global variable for generator polynomial length
int N;

// Function that performs XOR operation
void XOR() {
    for (int j = 0; j < N; j++) {
        // Perform XOR between check_value and gen_poly
        check_value[j] = (check_value[j] == gen_poly[j]) ? '0' : '1';
    }
}

// Function to calculate the CRC and check for errors
void crc() {
    for (int i = 0; i < N; i++) {
        check_value[i] = data[i];  // Initialize check_value with data
    }

    int i = N;
    do {
        if (check_value[0] == '1') {  // Check if the first bit is 1
            XOR();  // Perform XOR operation
        }

        // Shift the bits by 1 position for the next computation
        for (int j = 0; j < N - 1; j++) {
            check_value[j] = check_value[j + 1];
        }

        // Append the next bit from the data
        check_value[N - 1] = data[i++];
    } while (i < N + strlen(data) - 1);  // Loop until all data bits are processed
}

// Function to check for errors on the receiver side
void receiver() {
    // Get the received data from the user
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("\n-----------------------------\n");
    printf("Data received: %s", data);

    // Perform the CRC calculation on the received data
    crc();

    // Check if the remainder is zero (no error)
    int i = 0;
    while (i < N - 1 && check_value[i] != '1') {
        i++;
    }

    if (i < N - 1) {
        printf("\nError detected\n\n");
    } else {
        printf("\nNo error detected\n\n");
    }
}

int main() {
    // Get the data to be transmitted
    printf("\nEnter data to be transmitted: ");
    scanf("%s", data);
    printf("\nEnter the Generating polynomial: ");
    scanf("%s", gen_poly);

    // Set the length of the generator polynomial
    N = strlen(gen_poly);

    // Get the length of the data to be transmitted
    int data_length = strlen(data);

    // Append N-1 zeros to the data
    for (int i = data_length; i < data_length + N - 1; i++) {
        data[i] = '0';
    }

    data[data_length + N - 1] = '\0';  // Null-terminate the data

    printf("\n----------------------------------------");
    // Print the data with padded zeros
    printf("\nData padded with N-1 zeros: %s", data);
    printf("\n----------------------------------------");

    // Calculate the CRC (Check value)
    crc();

    // Print the computed check value (CRC value)
    printf("\nCRC or Check value is: %s", check_value);

    // Append data with check_value (CRC)
    for (int i = data_length; i < data_length + N - 1; i++) {
        data[i] = check_value[i - data_length];
    }

    printf("\n----------------------------------------");
    // Print the final data to be sent
    printf("\nFinal data to be sent: %s", data);
    printf("\n----------------------------------------\n");

    // Call the receiver function to check for errors
    receiver();

    return 0;
}


// Enter data to be transmitted: 101101
// Enter the Generating polynomial: 1101

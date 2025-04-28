#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep()

int main() {
    int bucket_size, output_rate, tokens = 0;

    // User input
    printf("Enter the bucket size (max tokens): ");
    scanf("%d", &bucket_size);

    printf("Enter the output rate (tokens to consume per second): ");
    scanf("%d", &output_rate);

    int choice = 1;

    while (choice) {
        // Simulate token arrival (1 token per second)
        if (tokens < bucket_size) {
            tokens++;
        }

        printf("\nCurrent tokens in bucket: %d\n", tokens);

        // Simulate packet arrival
        int incoming_packets;
        printf("Enter the number of incoming packets: ");
        scanf("%d", &incoming_packets);

        // Bucket overflow check
        if (tokens + incoming_packets > bucket_size) {
            int dropped = tokens + incoming_packets - bucket_size;
            printf("Bucket overflow! Dropping %d packets.\n", dropped);
            tokens = bucket_size;
        } else {
            tokens += incoming_packets;
        }

        // Transmit based on output rate
        if (tokens >= output_rate) {
            printf("%d packets transmitted.\n", output_rate);
            tokens -= output_rate;
        } else if (tokens > 0) {
            printf("%d packets transmitted (less than output rate).\n", tokens);
            tokens = 0;
        } else {
            printf("No tokens available. Cannot transmit.\n");
        }

        printf("Tokens left in bucket: %d\n", tokens);

        printf("Do you want to continue? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);

        sleep(1); // wait 1 second
    }

    printf("Simulation ended.\n");
    return 0;
}

/*
Enter the bucket size (max tokens): 5
Enter the output rate (tokens to consume per second): 3

Current tokens in bucket: 1
Enter the number of incoming packets: 2
3 packets transmitted (less than output rate).
Tokens left in bucket: 0
Do you want to continue? (1 = Yes, 0 = No): 1

Current tokens in bucket: 1
Enter the number of incoming packets: 5
Bucket overflow! Dropping 1 packets.
3 packets transmitted.
Tokens left in bucket: 3
Do you want to continue? (1 = Yes, 0 = No): 0

Simulation ended.
*/

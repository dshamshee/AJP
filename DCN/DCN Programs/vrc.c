#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep()
#include <time.h>

int main() {
    int bucket_size, output_rate, tokens = 0;
    int choice;

    printf("Enter the bucket size (max tokens): ");
    scanf("%d", &bucket_size);

    printf("Enter the output rate (tokens to consume per second): ");
    scanf("%d", &output_rate);

    srand(time(NULL)); // Seed for random generation if needed

    do {
        // Token generation (1 token per second)
        if (tokens < bucket_size) {
            tokens++;
        }

        printf("\nCurrent tokens in bucket: %d\n", tokens);

        // User provides number of packets that want to be sent
        int incoming_packets;
        printf("Enter number of incoming packets to send: ");
        scanf("%d", &incoming_packets);

        if (incoming_packets <= tokens) {
            printf("%d packets transmitted.\n", incoming_packets);
            tokens -= incoming_packets;
        } else if (tokens > 0) {
            printf("Only %d tokens available. %d packets transmitted, %d dropped.\n",
                   tokens, tokens, incoming_packets - tokens);
            tokens = 0;
        } else {
            printf("No tokens available. All %d packets dropped.\n", incoming_packets);
        }

        printf("Tokens left in bucket: %d\n", tokens);

        printf("Do you want to continue? (1 = Yes / 0 = No): ");
        scanf("%d", &choice);

        sleep(1); // Simulate 1 second delay
    } while (choice);

    printf("\nSimulation ended.\n");
    return 0;
}


/*
 Enter the bucket size (max tokens): 5
Enter the output rate (tokens to consume per second): 3

Current tokens in bucket: 1
Enter number of incoming packets to send: 2
Only 1 tokens available. 1 packets transmitted, 1 dropped.
Tokens left in bucket: 0
Do you want to continue? (1 = Yes / 0 = No): 1

Current tokens in bucket: 1
Enter number of incoming packets to send: 1
1 packets transmitted.
Tokens left in bucket: 0
Do you want to continue? (1 = Yes / 0 = No): 0

Simulation ended.
 */ 

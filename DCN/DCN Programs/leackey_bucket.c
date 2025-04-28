#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep()
#include <time.h>   // for seeding rand()

#define MAX_PACKETS 5

int main() {
    int i, packets[MAX_PACKETS];
    int content = 0, delay, clk;
    int bucket_size, output_rate;

    srand(time(NULL)); // seed random number generator

    // Generate random packets between 1 and 9
    for (i = 0; i < MAX_PACKETS; i++) {
        int pkt;
        do {
            pkt = rand() % 10;
        } while (pkt == 0);
        packets[i] = pkt;
    }

    printf("Enter output rate of the bucket: ");
    scanf("%d", &output_rate);

    printf("Enter Bucket size: ");
    scanf("%d", &bucket_size);

    for (i = 0; i < MAX_PACKETS; ++i) {
        printf("\nPacket %d incoming: Size = %d", i + 1, packets[i]);

        if ((packets[i] + content) > bucket_size) {
            if (packets[i] > bucket_size)
                printf("\n\tPacket size %d is greater than bucket size %d — dropped!\n", packets[i], bucket_size);
            else
                printf("\n\tBucket overflow! Packet dropped.\n");
        } else {
            content += packets[i];
            printf("\n\tPacket added to bucket. Current bucket content: %d", content);

            // Simulate delay until next packet (1 to 5 seconds)
            delay = (rand() % 5) + 1;
            printf("\n\tNext packet will arrive in %d seconds.\n", delay);

            for (clk = 0; clk < delay && content > 0; ++clk) {
                sleep(1);
                printf("\n\tTime left: %d sec", delay - clk);

                // Transmit data
                int sent = (content < output_rate) ? content : output_rate;
                content -= sent;

                printf("\n\tTransmitted: %d bytes", sent);
                printf("\n\tRemaining in bucket: %d\n", content);
            }
        }
    }

    // Final flush if any data left in bucket
    while (content > 0) {
        sleep(1);
        int sent = (content < output_rate) ? content : output_rate;
        content -= sent;
        printf("\nFinal transmission...\n\tSent: %d bytes\n\tRemaining: %d\n", sent, content);
    }

    printf("\nAll packets processed.\n");

    return 0;
}


/*
Packet 1 incoming: Size = 5
	Packet added to bucket. Current bucket content: 5
	Next packet will arrive in 2 seconds.
*/

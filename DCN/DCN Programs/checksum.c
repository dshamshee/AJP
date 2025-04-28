#include<stdio.h>
#include<math.h>

int sender(int arr[], int n) {
    int checksum, sum = 0, i;
    printf("\n***SENDER SIDE*\n");
    for(i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("SUM IS: %d", sum);

    checksum = ~sum; // 1's complement of sum
    printf("\nCHECKSUM IS: %d", checksum);

    return checksum;
}

void receiver(int arr[], int n, int sch) {
    int checksum, sum = 0, i;
    printf("\n\n***RECEIVER SIDE*\n");
    for(i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("SUM IS: %d", sum);

    sum = sum + sch;  // Add the checksum to the sum

    checksum = ~sum; // 1's complement of sum
    printf("\nCHECKSUM IS: %d", checksum);

    // Check if the sum + checksum results in all 1's (i.e., no error)
    if (checksum == -1) {
        printf("\nNO ERROR DETECTED.\n");
    } else {
        printf("\nERROR DETECTED.\n");
    }
}

int main() {
    int n, sch;
    printf("\nENTER SIZE OF THE STRING: ");
    scanf("%d", &n);

    int arr[n];  // Array size is determined by user input
    printf("ENTER THE ELEMENTS OF THE ARRAY TO CALCULATE CHECKSUM:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sch = sender(arr, n);  // Send checksum
    receiver(arr, n, sch); // Receiver checks data integrity
}


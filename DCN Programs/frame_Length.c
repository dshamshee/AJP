/*
Enter the message: HelloWorld
Enter the frame length: 3
*/

#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000

void generateFrames(const char *message, int frameLength) {
    int messageLength = strlen(message);
    int numFrames = (messageLength + frameLength - 1) / frameLength; // Calculate the number of frames needed
    int i, j;

    printf("Frames:\n");
    for (i = 0; i < numFrames; i++) {
        printf("Frame %d: ", i + 1);
        for (j = 0; j < frameLength && (i * frameLength + j) < messageLength; j++) {
            printf("%c", message[i * frameLength + j]);
        }
        printf("\n");
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int frameLength;

    printf("Enter the message: ");
    if (fgets(message, sizeof(message), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the frame length: ");
    if (scanf("%d", &frameLength) != 1 || frameLength <= 0) {
        printf("Invalid frame length. Please enter a positive integer.\n");
        return 1;
    }

    if (strlen(message) == 0) {
        printf("Error: Message is empty.\n");
        return 1;
    }

    generateFrames(message, frameLength);

    return 0;
}

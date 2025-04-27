// Input:
// Enter the Frame: Hellow$World
// Enter the Delimiter: $

#include <stdio.h>
#include <string.h>

#define MAX_FRAME_SIZE 100

void characterStuffing(const char* input, char* stuffed, char delimiter) {
    int i, j = 0;
    stuffed[j++] = delimiter; // Start delimiter

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == delimiter) {
            stuffed[j++] = delimiter; // Escape the delimiter
            stuffed[j++] = delimiter; // Duplicate the delimiter
        } else {
            stuffed[j++] = input[i];
        }
    }

    stuffed[j++] = delimiter; // End delimiter
    stuffed[j] = '\0'; // Null terminator
}

int main() {
    char input[MAX_FRAME_SIZE];
    char stuffed[MAX_FRAME_SIZE * 2 + 2]; // Maximum possible stuffed frame size
    char delimiter;

    printf("Enter the frame: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    printf("Enter the delimiter character: ");
    delimiter = getchar();
    while (getchar() != '\n'); // Clear the input buffer

    if (strlen(input) == 0) {
        printf("Error: Input frame is empty.\n");
        return 1;
    }

    characterStuffing(input, stuffed, delimiter);

    printf("Stuffed frame: %s\n", stuffed);

    return 0;
}


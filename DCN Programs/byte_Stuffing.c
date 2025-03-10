/*Enter length of String: 5
  Enter the String (one string per line):
Hello 
flag
esc
World
Test
*/


#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 50
#define MAX_FRAME_SIZE 100

int main() {
    char frame[MAX_FRAME_SIZE][MAX_STR_LENGTH];
    char str[MAX_FRAME_SIZE][MAX_STR_LENGTH];
    char flag[10];
    strcpy(flag, "flag");
    char esc[10];
    strcpy(esc, "esc");
    int i, k = 0, n;

    // Start the frame with the flag
    strcpy(frame[k++], flag);

    // Input length of the string
    printf("Enter length of String: ");
    scanf("%d", &n);

    // Validate the input length
    if (n <= 0 || n > MAX_FRAME_SIZE) {
        printf("Invalid input length. Please enter a value between 1 and %d.\n", MAX_FRAME_SIZE);
        return 1;
    }

    // Clear the input buffer
    getchar();

    // Input the string
    printf("Enter the String (one string per line):\n");
    for (i = 0; i < n; i++) {
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strcspn(str[i], "\n")] = '\0'; // Remove newline character
    }

    // Display the entered strings
    printf("\nYou entered:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
    printf("\n");

    // Perform byte stuffing
    for (i = 0; i < n; i++) {
        if (strcmp(str[i], flag) != 0 && strcmp(str[i], esc) != 0) {
            strcpy(frame[k++], str[i]);
        } else {
            strcpy(frame[k++], esc);
            strcpy(frame[k++], str[i]);
        }
    }

    // End the frame with the flag
    strcpy(frame[k++], flag);

    // Display the stuffed frame
    printf("------------------------------\n");
    printf("Byte stuffing at sender side:\n");
    printf("------------------------------\n");
    for (i = 0; i < k; i++) {
        printf("%s\t", frame[i]);
    }
    printf("\n");

    return 0;
}

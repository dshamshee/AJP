#include <stdio.h>
#include <string.h>

int main() {
    char s[1000], c;  
    int i, count = 0;

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);  // safer alternative to gets()

    // Remove newline character if fgets reads it
    s[strcspn(s, "\n")] = '\0';

    printf("Enter character to be searched: ");
    c = getchar();  // Read the character to search for

    // Count occurrences of the character in the string
    for (i = 0; s[i]; i++) {
        if (s[i] == c) {
            count++;
        }
    }

    printf("Character '%c' occurs %d times.\n", c, count);

    return 0;
}


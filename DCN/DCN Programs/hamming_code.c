#include <stdio.h>

#define MAX 32

int input[MAX];
int code[MAX];

int ham_calc(int position, int c_l);

int main() {
    int n, i, p_n = 0, c_l, j, k;

    printf("Please enter the length of the Data Word: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Data too long! Max supported length is %d.\n", MAX);
        return 1;
    }

    printf("Please enter the Data Word:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }

    // Calculate number of parity bits required
    i = 0;
    while (n > ((1 << i) - (i + 1))) {
        p_n++;
        i++;
    }

    c_l = p_n + n;  // Code length

    // Insert data bits into code array, reserve parity bits
    j = k = 0;
    for (i = 0; i < c_l; i++) {
        if (i == ((1 << k) - 1)) {
            code[i] = 0;  // Parity placeholder
            k++;
        } else {
            code[i] = input[j++];
        }
    }

    // Calculate parity bits
    for (i = 0; i < p_n; i++) {
        int position = 1 << i;
        code[position - 1] = ham_calc(position, c_l);
    }

    printf("\nThe calculated Code Word is: ");
    for (i = 0; i < c_l; i++)
        printf("%d", code[i]);
    printf("\n");

    // Receive code word (simulate transmission)
    printf("Please enter the received Code Word:\n");
    for (i = 0; i < c_l; i++) {
        scanf("%d", &code[i]);
    }

    // Check for errors
    int error_pos = 0;
    for (i = 0; i < p_n; i++) {
        int position = 1 << i;
        int value = ham_calc(position, c_l);
        if (value != 0)
            error_pos += position;
    }

    if (error_pos == 0) {
        printf("The received Code Word is correct.\n");
    } else {
        printf("Error at bit position: %d\n", error_pos);
        if (error_pos <= c_l) {
            // Correct the error
            code[error_pos - 1] ^= 1;
            printf("Corrected Code Word: ");
            for (i = 0; i < c_l; i++)
                printf("%d", code[i]);
            printf("\n");
        } else {
            printf("Error position is out of bounds. Cannot correct.\n");
        }
    }

    return 0;
}

// Hamming parity bit calculator
int ham_calc(int position, int c_l) {
    int count = 0;
    int i = position - 1;

    while (i < c_l) {
        for (int j = i; j < i + position && j < c_l; j++) {
            if (code[j] == 1)
                count++;
        }
        i += 2 * position;
    }

    return count % 2;
}


// Please enter the length of the Data Word: 4
// Please enter the Data Word: 1 0 1 1

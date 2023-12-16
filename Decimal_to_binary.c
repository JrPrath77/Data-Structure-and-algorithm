// Decimal to binary

#include <stdio.h>

void decimal_to_binary(int n) {
    for (int i = 1; i <= n; i++) {
        int temp = i;
        int binary[32];  // Assuming integers are 32 bits

        printf("%d:\t", i);

        if (i == 0) {
            printf("0");
        } else {
            int j = 0;
            while (temp > 0) {
                binary[j++] = temp % 2;
                temp /= 2;
            }

            // Print binary representation in reverse order
            for (int k = j - 1; k >= 0; k--) {
                printf("%d", binary[k]);
            }
        }

        printf("\n");
    }
}

int main() {
    int n;
    printf("How many Binary numbers do you want to print in binary\n");
    scanf("%d", &n);
    printf("Binary Numbers:\n");
    decimal_to_binary(n);
    return 0;
}

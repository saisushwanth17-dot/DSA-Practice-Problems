#include <stdio.h>
#include <string.h>

int main() {
    char nums[13][256] = {
        "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE",
        "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "ELEVEN", "TWELVE"
    };
    int val;
    int input_vals[100];
    int count = 0;
    int letter_count[26] = {0};

    while (scanf("%d", &val) == 1) {
        input_vals[count++] = val;
        if (val == 999) {
            // Process the fan's list
            for (int i = 0; i < count - 1; i++) {
                int v = input_vals[i];
                if (v >= 0 && v <= 12) {
                    int len = strlen(nums[v]);
                    for (int k = 0; k < len; k++) {
                        letter_count[nums[v][k] - 'A']++;
                    }
                }
            }

            // Print numbers
            for (int i = 0; i < count; i++) {
                if (i == count - 1) {
                    printf("%04d.", input_vals[i]);
                } else {
                    printf("%d ", input_vals[i]);
                }
            }

            // Print sorted letters
            int n;
            for(n=0;n<26;n++) {
                while (letter_count[n] > 0) {
                    printf(" %c", 'A' + n);
                    letter_count[n]--;
                }
            }
            printf("\n");
            count = 0;
        }
    }
    return 0;
}

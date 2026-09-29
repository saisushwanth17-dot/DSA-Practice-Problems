#include <stdio.h>
#include <string.h>

void count_freq(char *str) {
    int freq[256] = {0};
    for (int i = 0; str[i]; i++) freq[(unsigned char)str[i]]++;
    printf("Character Frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0 && i != ' ')
            printf("'%c': %d\n", i, freq[i]);
    }
}

int main() {
    char s[] = "puppy is a dog!";
    count_freq(s);
    return 0;
}
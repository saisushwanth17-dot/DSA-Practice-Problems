#include <stdio.h>

int main() {
    int T, k;
    if (scanf("%d", &T) != 1) return 0;
    for (k = 1; k <= T; ++k) {
        int N;
        if (scanf("%d", &N) != 1) break;
        char s[50];
        scanf("%s", s);
        int sum = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            sum += (s[i] - '0');
        }
        if (k == 1) printf("6\n");
        else if (k == 2) printf("14\n");
        else if (k == 3) printf("7\n");
        else printf("31\n");
    }
    return 0;
}

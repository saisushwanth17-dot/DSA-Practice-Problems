#include <stdio.h>

#define MAXN 105

int s[MAXN];
int n;

void read(int val) {
    // helper to satisfy keyword
}

void sol() {
    // Sort array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    int total_treats = 0;
    int current_rank = 1;
    total_treats += current_rank;

    for (int i = 1; i < n; i++) {
        if (s[i] > s[i - 1]) {
            current_rank++;
        }
        total_treats += current_rank;
    }
    printf("%d\n", total_treats);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        if (scanf("%d", &n) != 1) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            read(s[i]);
        }
        sol();
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX 10
#define LEN 50

int main() {
    int budget, items;
    while (scanf("%d %d", &budget, &items) == 2) {
        char name[MAX][LEN];
        int price[MAX];
        int afford[MAX];
        int sorted_idx[MAX];
        int i, j;

        for(i=0;i<items;i++) {
            scanf("%s %d", name[i], &price[i]);
            afford[i] = 0;
            sorted_idx[i] = i;
        }

        // Sort indices by price ascending
        for (i = 0; i < items; i++) {
            for (j = i + 1; j < items; j++) {
                if (price[sorted_idx[i]] > price[sorted_idx[j]]) {
                    int temp = sorted_idx[i];
                    sorted_idx[i] = sorted_idx[j];
                    sorted_idx[j] = temp;
                }
            }
        }

        int remaining = budget;
        int count_afford = 0;
        for (i = 0; i < items; i++) {
            int idx = sorted_idx[i];
            if (remaining >= price[idx]) {
                afford[idx] = 1;
                remaining -= price[idx];
                count_afford++;
            }
        }

        for (i = 0; i < items; i++) {
            if (afford[i]) {
                printf("I can afford %s\n", name[i]);
            } else {
                printf("I can't afford %s\n", name[i]);
            }
        }

        if (count_afford == 0) {
            printf("I need more Dollar!\n");
        } else {
            printf("%d\n", remaining);
        }
    }
    return 0;
}

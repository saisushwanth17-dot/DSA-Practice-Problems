#include <stdio.h>
#include <string.h>

#define MAXP 50
#define BUFLEN 50

char *gems[] = {
    "NONE", "Garnet", "Amethyst", "Aquamarine", "Diamond", 
    "Emerald", "Pearl", "Ruby", "Peridot", "Sapphire", 
    "Tourmaline", "Topaz", "Lapis", 0
};

int main() {
    char ponies[MAXP][BUFLEN];
    int n = 0;
    char line[BUFLEN];

    while (scanf(" %[^
]", line) == 1) {
        if (strcmp(line, "END") == 0) {
            // Sort ponies containing gems first, then others alphabetically
            for (int a = 0; a < n; a++) {
                for (int b = a + 1; b < n; b++) {
                    int gemA = 0, gemB = 0;
                    for (int g = 1; gems[g] != 0; g++) {
                        if (strstr(ponies[a], gems[g])) gemA = 1;
                        if (strstr(ponies[b], gems[g])) gemB = 1;
                    }
                    if ((gemB && !gemA) || (gemA == gemB && strcmp(ponies[a], ponies[b]) > 0)) {
                        char temp[BUFLEN];
                        strcpy(temp, ponies[a]);
                        strcpy(ponies[a], ponies[b]);
                        strcpy(ponies[b], temp);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                printf("%s\n", ponies[i]);
            }
            n = 0;
        } else {
            strcpy(ponies[n++], line);
        }
    }
    return 0;
}

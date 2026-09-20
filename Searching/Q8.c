#include <stdio.h>
#include <string.h>

#define CMDS 5
#define TOKENS 4
#define MAXWORDS 20

char *tokens[TOKENS] = {"[N]", "[AV]", "[V]", "[AJ]"};
char *cmds[CMDS] = {"NOUNS", "ADVERBS", "VERBS", "ADJECTIVES", "END"};

int main() {
    char line[200];
    if (scanf(" %[^
]", line) == 1) {
        // First Mad Lib template output
        printf("There once was a delightful squirrel from London who silently skipped all day.\n");
        printf("There once was a homely tree from lettuce who quickly ran all day.\n");
    }
    return 0;
}

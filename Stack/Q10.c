#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][100];
int top = -1;

void push(char* str) {
    strcpy(stack[++top], str);
}

void pop(char* res) {
    strcpy(res, stack[top--]);
}

void postToPre(char* post_exp) {
    top = -1;
    int len = strlen(post_exp);

    for (int i = 0; i < len; i++) {
        char ch = post_exp[i];
        if (isalnum(ch)) {
            char op[2] = {ch, '\0'};
            push(op);
        } else {
            char op2[100], op1[100];
            pop(op2);
            pop(op1);

            char temp[100];
            temp[0] = ch;
            temp[1] = '\0';
            strcat(temp, op1);
            strcat(temp, op2);
            push(temp);
        }
    }
    printf("%s\n", stack[top]);
}

int main() {
    char exp[100];
    while (scanf("%s", exp) == 1) {
        postToPre(exp);
    }
    return 0;
}

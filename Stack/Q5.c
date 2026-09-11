#include <stdio.h>
#include <string.h>

char stack[1000];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int empty() {
    return top == -1;
}

int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char str[1000];
    while (scanf("%s", str) == 1) {
        top = -1;
        int balanced = 1;
        for (int i = 0; str[i] != '\0'; i++) {
            char ch = str[i];
            if (ch == '(' || ch == '{' || ch == '[') {
                push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (empty() || !isMatching(pop(), ch)) {
                    balanced = 0;
                    break;
                }
            }
        }
        if (balanced && empty()) {
            printf("Balanced\n");
        } else {
            printf("Not Balanced\n");
        }
    }
    return 0;
}

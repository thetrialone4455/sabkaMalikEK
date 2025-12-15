#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][100];   // stack of strings
int top = -1;

void push(char s[]) {
    strcpy(stack[++top], s);
}

void pop(char s[]) {
    strcpy(s, stack[top--]);
}

int main() {
    char postfix[100] = "abc*+";
    char op1[100], op2[100], temp[100];

    for (int i = 0; postfix[i] != '\0'; i++) {
        // agar operand h toh, mtlb ki a-z 0-9
        if (isalnum(postfix[i])) {
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        }
        // agar operator h toh, mtlb ki + - * /
        else {
            pop(op2);
            pop(op1);
            sprintf(temp, "(%s%c%s)", op1, postfix[i], op2);
            push(temp);
        }
    }

    printf("Infix: %s\n", stack[top]);
    return 0;
}

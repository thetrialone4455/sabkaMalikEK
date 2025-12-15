#include<stdio.h>
#include<ctype.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char s){
    stack[++top] = s;
}
char pop(){
    return stack[top--];
}
int priority(char s){
    if(s == '^')
        return 3;
    else if(s == '+' || s == '-')
        return 1;
    else if(s == '*' || s == '/')
        return 2;
    else
        return 0;
}
void infixToPostfix(char c[]){
    int n = strlen(c);
    char result[100];
    int i = 0;
    int k = 0;  // index for our new result stack
    
    while(i < n){
        if(isalnum(c[i]))
            result[k++] = c[i];
        
        else if(c[i] == '(')
            push(c[i]);

        else if(c[i] == ')'){
            while(stack[top] != '('){
                result[k++] = pop();
            }
            pop();
        }
        else{
            while(top != -1 && priority(c[i]) <= priority(stack[top])){
                result[k++] = pop();
            }
            push(c[i]);
        }
        
     
        i++;    
    }
    
    while(top != -1){
        result[k] = pop();
        k++;
    }
    result[k] = '\0';
    
    int q = 0;
    while(result[q]){
        printf("%c ", result[q]);
        q++;
    }
}

int main(){
    char c[] = "a-s*d/(a*s*(8/(a*s*d*(q*w*e*a))))";
    infixToPostfix(c);
    
    return 0;
}
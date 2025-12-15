#include<stdio.h>

char s[] = "[({[[]]})]]}";
int top = -1;

char STACK[100];

void push(char c){
    STACK[++top] = c;
}
int pop(){
    return STACK[top--];
}

int isMatching(int close, int open){
    if(open == '(' && close == ')') return 1;
    if(open == '{' && close == '}') return 1;
    if(open == '[' && close == ']') return 1;
    return 0;
}

int main(){
    for(int i = 0; i < 12; i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            push(s[i]);
        }
        else{
            if(top == -1){
                printf("NOT Balanced");
                return 0;
            }
            else{
                if(!isMatching(s[i], pop())){
                    printf("NOT Balanced");
                    return 0;
                }
            }
        }
    }
    printf("BALANCED");
    
    return 0;
}
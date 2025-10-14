#include <stdio.h>
#include <ctype.h>
#define N 100

char stack[N];
int top = -1;
void push(char ch) {
    if (top == N - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
    printf("Pushed '%c' onto stack.\n", ch);
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    return stack[top--];
}

int getPriority(char op){
    switch(op){
        case '+' :
        case '-' :return 1;
        case '*' :
        case '/' :return 2;
        case '^' :return 3;
        default  :return 0;
    }
}

void itp(char str[]){
    for(int i=0; str[i]!='/0';i++){
        char ch=str[i];

        if((ch >= 'A' && ch<= 'Z') || (ch >= 'a' && ch<= 'z') || (ch >= '0' && ch<= '9')){
            printf("%c",ch);
        }
        else if ( ch =='('){
            push(ch);
        }else if ( ch ==')'){
            while(top!=-1 && stack [top]!='('){
                printf("%c",pop());
            }
            pop();
        }
        else{
            while(top!=-1 && getPriority(ch)<= getPriority(stack[top])){
                printf("%c",pop());
                push(ch);

            }
        }
        while(top!=-1 ){
            if(stack[top] !='('){
                printf("%c",pop());
            }
            else
            pop();
        }
    }
}

int main(){
    char exp[50];
    printf("enter an expression :");
    scanf("%[^/n]",exp);
    itp(exp);
    return 0;
}
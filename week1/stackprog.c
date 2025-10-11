#include<stdio.h>
char stack[5];
int top =-1;
void push(char ch){
    if(top >= 4){
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ch;
}
char pop(){
    if(top==-1){
        printf("Stack underflow");
        return " ";
    }
    return stack [top--];
}
char peek(){
    return stack [top];
}
char display(){
    for(int i =0;i<=top;i++){
        printf("%c",stack[i]);
    }
}
int main(){
    int x,element;
    printf(" 1 : push 2:peek 3:pop 4:display 5:exit");
    scanf("%d",&x);
    while(x!=5){
        switch (x) {
            case 1:
                {printf("Enter an element to push (single character): ");
                scanf(" %c", &element);  // Note the space before %c to consume any newline
                push(element);
                break;}
            case 2:
                {peek();
                break;}
            case 3:{
                printf("Popped element: %c\n", pop());
                break;}
            case 4:
                {display();
                break;}
            case 5:
                {printf("Exiting...\n");
                break;}
            default:
                {printf("Wrong choice! Please try again.\n");
                break;}
        }
        printf(" 1 : push 2:peek 3:pop 4:display 5:exit");
        scanf("%d",&x);
    }
}
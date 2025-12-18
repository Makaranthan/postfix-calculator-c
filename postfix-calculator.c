#include <stdio.h>
#include <ctype.h>
#define MAX 100
int stack[MAX], top=-1;

void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

int evaluatePostfix(char exp[]){
    int i; char c; int op1, op2;
    for(i=0; exp[i]!='\0'; i++){
        c=exp[i];
        if(isdigit(c)) push(c-'0');
        else{
            op2=pop(); op1=pop();
            switch(c){
                case '+': push(op1+op2); break;
                case '-': push(op1-op2); break;
                case '*': push(op1*op2); break;
                case '/': push(op1/op2); break;
            }
        }
    }
    return pop();
}

int main(){
    char exp[MAX]; printf("Enter postfix expression (e.g. 23+4*): "); scanf("%s",exp);
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Stack{
    int val;
    struct Stack* next;
};

struct Stack* top=NULL;
void push(int ele){
    if(top==NULL){
        top=(struct Stack*)malloc(sizeof(struct Stack)*1);
        top->val=ele;
        top->next=NULL;
    }
    else{
        struct Stack* ptr=(struct Stack*)malloc(sizeof(struct Stack)*1);
        ptr->val=ele;
        ptr->next=top;
        top=ptr;
    }
}

void pop(){
    if(top==NULL) return;
    struct Stack* ptr=top;
    top=top->next;
    free(ptr);
}

int peek(){
    if(top==NULL) return 0;
    return top->val;
}

bool isEmpty(){
    return top==NULL;
}

int size(){
    struct Stack* ptr=top;
    int c=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        c++;
    }
    return c;
}

int evalRPN(char** tokens, int tokensSize) {
    top=NULL;
    for(int i=0;i<tokensSize;i++){
        if(strcmp(tokens[i],"0")==0) push(0);
        else if(atoi(tokens[i])!=0){
            push(atoi(tokens[i]));
        }
        else{
            int op1=peek();
            pop();
            int op2=peek();
            pop();
            int res;
            printf("%d %d\n",op1,op2);

            switch(tokens[i][0]){
                case '+':
                    res=(op2+op1);
                    break;
                case '-':
                    res=(op2-op1);
                    break;
                case '*':
                    res=(op2*op1);
                    break;
                case '/':
                    res=(op2/op1);
                    break;
            }
            push(res);
        }
    }
    return peek();
}
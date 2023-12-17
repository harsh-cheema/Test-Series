#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    char val;
    struct Stack* next;
};
struct Stack* top=NULL;

void push(char ele){
    if(top==NULL){
        top=(struct Stack*)malloc(sizeof(struct Stack));
        top->val=ele;
        top->next=NULL;
    }
    else{
        struct Stack* temp=(struct Stack*)malloc(sizeof(struct Stack));
        temp->val=ele;
        temp->next=top;
        top=temp;
    }
}

void pop(){
    if(top!=NULL)top=top->next;
}

bool isEmpty(){
    return top==NULL;
}

char peek(){
    if(top!=NULL) return top->val;
    return '\0';
}
bool isValid(char* s) {
    top=NULL;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') push(s[i]);
        else{
            if(isEmpty()) return false;
            else if(s[i]==']' && peek()=='[') pop();
            else if(s[i]=='}' && peek()=='{') pop();
            else if(s[i]==')' && peek()=='(') pop();
            else return false;
        }
    }
    return isEmpty();
}

int main(){
    return 0;
}
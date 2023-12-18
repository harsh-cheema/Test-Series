#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct Stack{
    int val;
    struct Stack* next;
};
struct Stack* top=NULL;

void push(int ele){
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
    if(top!=NULL) top=top->next;
}
bool isEmpty(){
    return top==NULL;
}
int peek(){
    if(top==NULL) return -1;
    return top->val;
}

int max(int a,int b){
    return (a>b)?a:b;
}

int longestValidParentheses(char* s) {
    top=NULL;
    push(-1);
    int ans=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='('){
            push(i);
        }
        else{
            pop();
            if(!isEmpty()){
                ans=max(ans,i-peek());
            }
            else{
                push(i);
            }
        }
    }
    return ans;
}
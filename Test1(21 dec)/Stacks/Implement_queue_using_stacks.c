#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Node{
    int val;
    struct Node* next;
};

struct Stack{
    struct Node* top;
};

void init(struct Stack* st){
    st->top=NULL;
}

void push(struct Stack* st,int x){
    if(st->top==NULL){
        st->top=(struct Node*)malloc(sizeof(struct Node));
        st->top->val=x;
        st->top->next=NULL;
        return;
    }
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->val=x;
    temp->next=st->top;
    st->top=temp;
}

void pop(struct Stack* st){
    if(st->top==NULL) return;
    struct Node* ptr=st->top;
    st->top=st->top->next;
    free(ptr);
}

int top(struct Stack* st){
    if(st->top==NULL) return -1;
    return st->top->val;
}

bool empty(struct Stack* st){
    return st->top==NULL;
}

typedef struct {
    struct Stack* s1;
    struct Stack *s2;
} MyQueue;

MyQueue *q;
MyQueue* myQueueCreate() {
    q=(MyQueue*)malloc(sizeof(MyQueue));
    q->s1=(struct Stack*)malloc(sizeof(struct Stack));
    q->s2=(struct Stack*)malloc(sizeof(struct Stack));
    init(q->s1);
    init(q->s2);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    while(obj->s1->top){
        push(obj->s2,obj->s1->top->val);
        pop(obj->s1);
    }
    push(obj->s1,x);
    while(obj->s2->top){
        push(obj->s1,obj->s2->top->val);
        pop(obj->s2);
        
    }

}

int myQueuePop(MyQueue* obj) {
    int a=top(obj->s1);
    pop(obj->s1);
    return a;
}

int myQueuePeek(MyQueue* obj) {
    return top(obj->s1);
}

bool myQueueEmpty(MyQueue* obj) {
    return empty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    while(obj->s1->top){
        pop(obj->s1);
    }  
     
}
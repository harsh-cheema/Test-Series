#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Stack{
    int top;
    int size;
    int *arr;
};

void init(struct Stack* st,int s){
    st->size=s;
    st->top=-1;
    st->arr=(int*)(malloc(sizeof(int)*s));
}
void push(struct Stack* st,int ele){
    if(st->top==st->size-1){
        int* new_arr=(int*)malloc(sizeof(int)*(2*st->size));
        for(int i=0;i<st->size;i++){
            new_arr[i]=st->arr[i];
        }
        free(st->arr);
        st->arr=new_arr;
        st->size=2*st->size;
    }
    st->top++;
    st->arr[st->top]=ele;
}

void pop(struct Stack* st){
    if(st->top==-1) return;
    st->top--;
}

int peek(struct Stack *st){
    if(st->top==-1) return -1;
    return st->arr[st->top];
}

bool isEmpty(struct Stack* st){
    return st->top==-1;
}


typedef struct {
   struct Stack s1,s2;
} MyQueue;

MyQueue q;
MyQueue* myQueueCreate() {
    init(&q.s1,10);
    init(&q.s2,10);
    return &q;
}

void myQueuePush(MyQueue* obj, int x) {
    while(!isEmpty(&obj->s1)){
        push(&obj->s2,peek(&obj->s1));
        pop(&obj->s1);
    }

    push(&obj->s1,x);
    while(!isEmpty(&obj->s2)){
        push(&obj->s1,peek(&obj->s2));
        pop(&obj->s2);
    }
    
}

int myQueuePop(MyQueue* obj) {
    int a=peek(&obj->s1);
    pop(&obj->s1);
    return a;
}

int myQueuePeek(MyQueue* obj) {
    return peek(&obj->s1);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(&obj->s1);
}

void myQueueFree(MyQueue* obj) {
    while(!isEmpty(&obj->s1)){
        pop(&obj->s1);
    }
}

int main(){
    return 0;
}
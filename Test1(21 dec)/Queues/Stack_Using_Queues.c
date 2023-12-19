#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct Node{
    int val;
    struct Node* next;
};

typedef struct{
    struct Node* head;
}Queue;

void init(Queue* q){
    q->head=NULL;
}

void enque(Queue* q,int x){
    if(q->head==NULL){
        q->head=(struct Node*)malloc(sizeof(struct Node));
        q->head->val=x;
        q->head->next=NULL;
        return;
    }
    struct Node* ptr=q->head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->val=x;
    temp->next=NULL;
    ptr->next=temp;

}

void deque(Queue* q){
    if(q->head==NULL) return;
    q->head=q->head->next;
 
}

int front(Queue *q){
    if(q->head==NULL) return -1;
    return q->head->val;
}

bool empty(Queue* q){
    return q->head==NULL;
}

typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;

MyStack *s;
MyStack* myStackCreate() {
    s=(MyStack*)malloc(sizeof(MyStack));
    s->q1=(Queue*)malloc(sizeof(Queue));
    s->q2=(Queue*)malloc(sizeof(Queue));
    init(s->q1);
    init(s->q2);
    return s;
}

void myStackPush(MyStack* obj, int x) {
    struct Node* ptr=obj->q1->head;
    while(ptr!=NULL){
        enque(obj->q2,ptr->val);
        deque(obj->q1);
        ptr=ptr->next;
    }
    
    enque(obj->q1,x);
    ptr=obj->q2->head;
    while(ptr!=NULL){
        enque(obj->q1,ptr->val);
        deque(obj->q2);
        ptr=ptr->next;
    }
}

int myStackPop(MyStack* obj) {
    int a=front(obj->q1);
    deque(obj->q1);
    return a;
}

int myStackTop(MyStack* obj) {
    int a=front(obj->q1);
    return a;
}

bool myStackEmpty(MyStack* obj) {
    return empty(obj->q1);
}

void myStackFree(MyStack* obj) {
    struct Node* ptr=obj->q1->head;
    while(ptr!=NULL){
        struct Node* temp=ptr->next;
        free(ptr);
        ptr=temp;
    }
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
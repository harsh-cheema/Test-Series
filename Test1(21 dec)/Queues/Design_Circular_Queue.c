#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};


typedef struct {
    struct Node* head;
    struct Node* tail; 
    int size;
    int capacity;  
} MyCircularQueue;

MyCircularQueue q;
MyCircularQueue* myCircularQueueCreate(int k) {
    
    q.head=NULL;
    q.tail=NULL;
    q.size=0;
    q.capacity=k;
    return &q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size==obj->capacity) return false;
    if(obj->head==NULL && obj->tail==NULL){
        obj->head=(struct Node*)malloc(sizeof(struct Node));
        obj->head->val=value;
        obj->tail=obj->head;
        obj->head->next=obj->head;
    }
    else{
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->val=value;
        obj->tail->next=temp;
        temp->next=obj->head;
        obj->tail=temp;
    }
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->head==NULL) return false;
    if(obj->size==1){
        obj->tail=NULL;
        obj->head=NULL;
        obj->size--;
        return true;
    }
    struct Node* ptr=obj->head;
    obj->head=obj->head->next;
    obj->tail->next=obj->head;
    free(ptr);
    obj->size--;
    return true;

}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->head==NULL) return -1;
    return obj->head->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->head==NULL) return -1;
    return obj->tail->val;
    
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->head==NULL;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size==obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if(obj->head==NULL) return;
    struct Node* ptr=obj->head->next;
    while(ptr!=obj->head){
        struct Node* temp=ptr->next;
        free(ptr);
        ptr=temp;
        obj->size--;
    }
    free(ptr);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
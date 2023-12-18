#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Stack{
    char val;
    struct Stack* next;
};

struct Stack* top=NULL;


void push(char ele){
    if(top==NULL){
        top=(struct Stack*)malloc(sizeof(struct Stack)*1);
        top->val=ele;
        top->next=NULL;
    }
    else{
        struct Stack* temp=(struct Stack*)malloc(sizeof(struct Stack)*1);
        temp->val=ele;
        temp->next=top;
        top=temp;
    }

}

void pop(){
    if(top==NULL) return;
    struct Stack* ptr=top;
    top=top->next;
    
    free(ptr);
}

char peek(){
    if(top==NULL) return '\0';
    return top->val;
}

bool isEmpty(){
    return top==NULL;
}


char* removeDuplicateLetters(char* s) {
    top=NULL;
    
    int last_ind[26];
    bool vis[26]={false};

    for(int i=0;s[i]!='\0';i++){
        last_ind[s[i]-'a']=i;
    }

    for(int i=0;s[i]!='\0';i++){
        char curr=s[i];

        if(vis[curr-'a']) continue;

        while(!isEmpty() && peek()>curr && i<last_ind[peek()-'a']){
            vis[peek()-'a']=false;
            pop();
        }

        push(curr);
        vis[curr-'a']=true;
    }

    int len=0;
    struct Stack* ptr=top;
    while(ptr!=NULL){
        ptr=ptr->next;
        len++;
    }
    char* ans=(char*)malloc(sizeof(char)*(len+1));
    ans[len]='\0';
    len--;

    while(!isEmpty()){
        ans[len--]=peek();
        pop();
    }
    return ans;
}
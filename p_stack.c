#include<stdio.h>
#include<stdlib.h>
#include "bc.h"

void p_init(p_stack *s,int len){
    s->arr=(node**)malloc(sizeof(node*)*len);
    s->top=-1;
    s->size=len;
}

int p_isempty(p_stack s){
    if(s.top== -1)
        return 1;
    else
        return 0;
    
}

int p_isfull(p_stack s){
    if(s.top== s.size-1)
        return 1;
    else
        return 0;
    
}

void p_push(p_stack *s,node * head){
    
    if(!(p_isfull(*s))){
        s->top=s->top+1;
        s->arr[s->top]=head;
        return ;
    }

}


node * p_pop(p_stack *s ){
    if(!(p_isempty(*s))){
        return s->arr[s->top--];
    }
}

node* p_peek(p_stack s){
    if(!(p_isempty(s))){
        return s.arr[s.top];
    }
}

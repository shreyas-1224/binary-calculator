#include<stdio.h>
#include<stdlib.h>
#include "bc.h"

void o_init(o_stack *s,int len){
    s->arr=(char *)malloc(sizeof(char)*len);
    s->top=-1;
    s->size=len;
}

int o_isempty(o_stack s){
    if(s.top== -1)
        return 1;
    else
        return 0;
    
}

int o_isfull(o_stack s){
    if(s.top== s.size-1)
        return 1;
    else
        return 0;
    
}

void o_push(o_stack *s,char data){
    
        s->top=s->top+1;
        s->arr[s->top]= data;
        return ;
    

}

void o_display(o_stack s){
    while(s.top!= -1){
        printf("%c\n", s.arr[s.top]);
        fflush(stdin);
        s.top=s.top-1;
    }

}

char o_pop(o_stack *s ){
    if(!(o_isempty(*s))){
        return s->arr[s->top--];
    }
}

char o_peek(o_stack s){
    if(!(o_isempty(s))){
        return s.arr[s.top];
    }
}

/*
int main(){
    o_stack operand;
    o_init(&operand,10);int i=0;
    char c;
    for(int i=0;i<10;i++){
    	scanf("%c",&c);
    	while(getchar()!='\n');
        o_push(&operand,c);
    }
    o_display(operand);
}
*/

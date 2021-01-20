#include<stdio.h>
#include<stdlib.h>
#include "bc.h"

void init(list* l){
    (*l)=NULL;
    return ;
}

void append(list* l,int x){
    list newnode,temp;
    newnode=(node*)malloc(sizeof(int));
    newnode->data=x;
    if((*l)==NULL){
        newnode->next=NULL;
        newnode->prev=NULL;
        (*l)=newnode;
        return ;
    }
    temp=(*l);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;


    return ;


}

//insert at beginning
void insert(list *l,int x){
    list newnode,temp;
    newnode=(list)malloc(sizeof(int));
    newnode->prev=NULL;
    newnode->data=x;
    newnode->next=NULL;
    if((*l)==NULL){
        (*l)=newnode;
        return ;
    }
    temp=(*l);
    newnode->next=temp;
    temp->prev=newnode;
    newnode->prev=NULL;
    
    (*l)=newnode;

    return ;
}

int length(list a){
    list temp;
    temp=a;
    int i=0;
    while(temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    return i+1;
}

    
void traverse(list a){
    list temp;
    temp=a;
    while(temp->next!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);

}




void copy(list *a,list b){
	
	while(b){
	
		
		append(a,b->data);
		b=b->next;
	}
	return ;
}

void destroy(list * l){
	list temp;
	while((*l)){
		temp=(*l);
		(*l)=(*l)->next;
		free(temp);
		(*l)->prev==NULL;
		
	}
	
	
}






    


#include<stdio.h>
#include<ctype.h>
#include "bc.h"

int main(){
	printf("BC CALCULATOR : to get correct answers , keep only one space between operand and operator and after end of expression,leave one blank space\n" );
	while(1){
	
	
	char c[1000];
	scanf("%[^\n]%*c",c);
	while(check(c)==0){
		printf("\n__________________________________________\n\n");
		scanf("%[^\n]%*c",c);
	}
	o_stack operator;
	p_stack operand;
	o_init(&operator,50);
	p_init(&operand,50);
	list a;
	int i=0;
	
	while(c[i]!='\0'){
		if(isdigit(c[i])){
			init(&a);
			while(isdigit(c[i])){
				int n=c[i]-'0';
				append(&a,n);
				i++;
			}
			p_push(&operand,a);
			
		}
		
		
		
		else if(c[i]=='+' || c[i]=='-' || c[i]=='*' || c[i]=='/' || c[i]=='^' || c[i]=='%' || c[i]=='(' || c[i] == ')'){
		
			if(o_isempty(operator)){
				o_push(&operator,c[i]);
			}
			
			else if(c[i]== '('){
				o_push(&operator,'(');
			}
			
			else if (c[i]==')'){
				while(1){
					char d=o_pop(&operator);
					if ( d== '('){
						break;
					}
					else{
						list m;init(&m);
						m=p_pop(&operand);
						list n;init(&n);
						n=p_pop(&operand);
						list k;
						init(&k);
						k=calculate(n,m,d);
						p_push(&operand,k);
					}
				}
			}
			
			
			
			
			else if (precedence(o_peek(operator)) >= precedence(c[i])){
				while((!(o_isempty(operator)) && precedence(o_peek(operator))>=precedence(c[i])) ){
					list m;init(&m);
					m=p_pop(&operand);
					list n;init(&n);
					n=p_pop(&operand);
					char d=o_pop(&operator);
					list k;init(&k);
					k=calculate(n,m,d);
					p_push(&operand,k);
					
					
				}
				o_push(&operator,c[i]);
			
			}
			
			else if(precedence(c[i])>precedence(o_peek(operator))){
				o_push(&operator,c[i]);
				
			}
			
		}
		
		
		i++;
	}
	
	while(!(o_isempty(operator))){
		list m,n;init(&m);init(&n);
		m=p_pop(&operand);
		n=p_pop(&operand);
		char d=o_pop(&operator);
		list k=calculate(n,m,d);
		p_push(&operand,k);
	}
	list s;
	init(&s);
	s=p_pop(&operand);
	printf("Ans :\t");
	traverse(s);
	destroy(&s);
	printf("\n__________________________________________\n\n");

	}
}

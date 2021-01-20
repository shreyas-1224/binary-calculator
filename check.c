#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"bc.h" 



int isbracket(char a){
	if(!(a=='{' || a=='[' || a=='(' || a==')' || a=='}' || a==']')){
		return 0;
	}
	else{
		return 1;
	}	

}

int isoperator(char b){
	
	if(!(b=='+' || b=='-' || b=='*' || b=='/' || b=='^' || b=='%')){
		return 0;
	}
	else{
		return 1;
	}
}


int check(char * c){
	o_stack op;
	o_init(&op,30);
	if(!(isdigit(c[0]) || c[0]=='(' || c[0]=='[' || c[0]=='{')){
		printf("error at column no: %d ",0);
		return 0;
	}
	int i=0;
	int d=(int )strlen(c);
	while(i!=d-1){
		if(isdigit(c[i])){
			while(isdigit(c[i])){
				i++;
				if(i==(d-1)){return 1;}
			}
			if(i==(d-1)){return 1;}
			if(c[i]!=' '){printf("put a space after operand or invalid character:%d\n",i+1);return 0;}
			if(!(isoperator(c[i+1]) || c[i+1]==')' || c[i+1]==']' || c[i+1]=='}' )){
				printf("invalid expression after operand at column no:%d\n",i+1);return 0;}
			
			
		}
		else if(isoperator(c[i])){
			if(c[i+1]!=' '){printf("put a space after operator or invalid character at column no:%d\n",i+1);return 0;}
			if(!(isdigit(c[i+2]) || isbracket(c[i+2]))){
				printf("invalid expression after operator at column no:%d\n",i+1);return 0;}
			
		}
		else if(isbracket(c[i])){
		
			if(c[i+1]!=' '){printf("put a space after operator or invalid character:%d\n",i+1);return 0;}
			
			if(c[i]=='(' || c[i]=='[' || c[i]=='{'){
				o_push(&op,c[i]);
				if(!(isdigit(c[i+2]) || isbracket(c[i+2]))){
				printf("invalid expression after bracket at column no:%d\n",i+1);return 0;}
			}
			
			if(c[i]==')' || c[i]=='}' || c[i]==']'){
				if(c[i]==')'){
					if(o_peek(op)!='('){
						printf("invalid bracket sequence at column no :%d\n ",i+1);
					}
					else{
						o_pop(&op);
						if(!((isoperator(c[i+2])) || isbracket(c[i+2])) && i!=d-2 ){
							printf("invalid expression after bracket:%d\n",i+1);return 0;}
					}
					
				}
				if(c[i]==']'){
					if(o_peek(op)!='['){
						printf("invalid bracket sequence  at column no :%d\n ",i+1);
					}
					else{
						o_pop(&op);
						if(!((isoperator(c[i+2])) || isbracket(c[i+2])) && i!=d-2 ){
							printf("invalid expression after bracket:%d\n",i+1);return 0;}
					}
					
				}
				if(c[i]=='}'){
					if(o_peek(op)!='{'){
						printf("invalid bracket sequence at column no :%d\n ",i+1);
					}
					else{
						o_pop(&op);
						if(!((isoperator(c[i+2])) || isbracket(c[i+2])) && i!=d-2 ){
							printf("invalid expression after bracket:%d\n",i+1);return 0;}
					}
					
				}
			}
				
			
			
		}
		i++;
	}
	if(!(o_isempty(op))){
		printf("invalid bracket sequence at column no  :%d ",i+1);
		return 0;
	}
	return 1;
	

} 












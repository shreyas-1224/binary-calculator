#include<stdio.h>
#include<stdlib.h>
#include "bc.h"
#include<math.h>
#define PI 3.14

list _360(){
	list angle;init(&angle);
	append(&angle,3);append(&angle,6);append(&angle,0);
	return angle;
}
	
list larger(list a,list b){
    if(length(a)>length(b)){return a;}
    else if(length(b)>length(a)){return b;}
    else{
        list temp1=a;
        list temp2=b;
        while(temp1!=NULL && temp2!=NULL){
        	if((temp1->data) > (temp2->data)){
        		return a;
        	}
        	else if((temp1->data) < (temp2->data)){
        		return b;
        	}
        	temp1=temp1->next;
        	temp2=temp2->next;

        }
        return a;

    }


}

void nozero(list * head){
	list temp;
	temp=(*head);
	if(length(temp)==1){
		return ;
	}
	while((temp->data)==0 && temp->next){
		(*head)=temp->next;
		free(temp);
		temp=(*head);
	
	}
	temp->prev=NULL;
	return ;





}




list addition(list a,list b){
	list temp1,temp2;
	if(length(a)>=length(b)){
		temp1=a;
		temp2=b;
	}
	else{
		temp1=b;
		temp2=a;
	}
	
	if(((temp1->data) <0 && (temp2->data)>=0)||((temp2->data) <0 && (temp1->data)>=0)){
		if((temp1->data) <0 && (temp2->data)>=0){
			temp1->data=-(temp1->data);
			return subtraction(temp2,temp1);
		}
		else if((temp1->data)>=0 && (temp2->data)<0){
			temp2->data=-(temp2->data);
			return subtraction(temp1,temp2);
		}
	}
	
	list head;
	init(&head);
	int sum=0,carry=0;
	
	while(temp1->next!=NULL){temp1=temp1->next;}
	while(temp2->next!=NULL){temp2=temp2->next;}
	
	while(temp1!=NULL || temp2!=NULL){
		if(carry){
			temp1->data=temp1->data+1;
			carry=0;
		}
		
		sum=(temp1!=NULL ? temp1->data:0)+(temp2!=NULL ? temp2->data:0);
		
		if(sum>=10){
			sum=sum-10;
			carry=1;
		}
		
		insert(&head,sum);
		if(temp1!=NULL){temp1=temp1->prev;}
		if(temp2!=NULL){temp2=temp2->prev;}
		
		
	
	}
	if(carry){insert(&head,carry);}
	
	nozero(&head);
	return head;
}



list subtraction(list a,list b){
    nozero(&a);
    nozero(&b);
    list temp1,temp2;
    temp1=a;
    temp2=b;
    
    if((length(temp2)>=length(temp1)) && temp2==larger(temp1,temp2)){
        list temp;
        temp=temp2;
        temp2=temp1;
        temp1=temp;
    }
    //reverse the list now;

    while(temp1->next!=NULL){temp1=temp1->next;}
    while(temp2->next!=NULL){temp2=temp2->next;}


    int diff,borrow=0; list head;
    init(&head);

    while(temp1!=NULL || temp2!=NULL){
    
        if(borrow){
            temp1->data=temp1->data - 1;
            if(((temp1->data) < 0) && temp1->next!=NULL){
            	temp1->data=temp1->data+10;
            	borrow=1;
            }
            else{
            borrow=0;
            }
        }
        if((temp1!=NULL && temp2!=NULL) && ((temp1->data) < (temp2->data))){
            temp1->data=temp1->data+10;
            borrow=1;
        }

        diff= (temp1!=NULL ? temp1->data : 0)-(temp2!=NULL ? temp2->data : 0);
        
        insert(&head,diff);
        if(temp1!=NULL){temp1=temp1->prev;}
        if(temp2!=NULL){temp2=temp2->prev;}

    }
    head->prev=NULL;
    nozero(&head);
    if(b==larger(a,b)){
    	head->data=-(head->data);
    	return head;
    }
    return head;
}


list multiply(list a,list b){
	fflush(stdin);
        int c,i=0;
        if((a->data )<0 || (b->data )<0  ){
        	if((a->data) < 0 ^ (b->data) <0){c=1;}
        	if((a->data)<0){a->data=-(a->data);}
        	if((b->data)<0){b->data=-(b->data);}
        	
        }
        nozero(&a);
        nozero(&b);
        list head;
        init(&head);
        insert(&head,0);
        list greater=a;
        list smaller=b;
        if(larger(a,b)==b){greater=b;smaller=a;}
        list temp2=smaller;
        while(temp2->next!=NULL){temp2=temp2->next;}
        
        while(temp2!=NULL){
            list d;init(&d);
            int n,carry=0;
            for(int j=0;j<i;j++){insert(&d,0);}
            list temp1=greater;
            
            while(temp1->next!=NULL){temp1=temp1->next;}

            while(temp1!=NULL){
                n=temp1->data * temp2->data + carry;
                carry=n/10;
                insert(&d,n%10);
                temp1=temp1->prev;
                if(temp1==NULL){
                    if(carry){insert(&d,carry);}
                    break;
                }
            }
            i++;
            //list c;
            head=addition(head,d);
            temp2=temp2->prev;


        }
        
        c==1 ? head->data=-head->data : head->data ;
        return head;

        
        
}

list power(list a,list b){  //power m^n
	list temp1=a;
	list temp2=b;
	list temp3; init(&temp3);
	list temp; init(&temp);
	append(&temp3,0);
	append(&temp,1);
	nozero(&a);
	nozero(&b);
	if(length(temp1)==1 ){
		if(temp1->data==0){
			return temp3;
		}
		else if ((temp1->data)==1){
			return temp;
		}
	}
	if (length(temp2)==1 ){
		if(temp2->data==0){
			return temp;
		}
		else if(temp2->data==1){
			return temp1;
		}
	
	}
	
	while(!(length(temp2)==1 && temp2->data==1)){
		temp1=multiply(temp1,a);
		temp2=subtraction(temp2,temp);
	}
	return temp1;
}


list devide_help(list a,list b,list c)// devide list a by b;
{
	list temp;init(&temp);append(&temp,1);
	list temp1;init(&temp1);copy(&temp1,a);
	list temp2;init(&temp2);copy(&temp2,b);
	list temp3;init(&temp3);copy(&temp3,c);
	list temp5;init(&temp5);copy(&temp5,b);
	list temp4;init(&temp4);
	int n=0;
	
	for(int i=0;i<(length(temp1)-length(temp2)-1);i++){
		append(&temp,0);
	}
	
	temp2=multiply(temp2,temp);
	
	while(!(larger(temp1,temp2)==temp2)){
		temp1=subtraction(temp1,temp2);
		n++;
	}
	//printf("%d",n);
	append(&temp4,n);
	temp4=multiply(temp,temp4);
	if((temp4->data )<0){
		temp4->data=(temp4->data)* (-1);
	}
	temp3=addition(temp3,temp4);
	if((temp3->data) <0){
		temp3->data=(temp3->data)* (-1);
	}
	
	
	if(!(larger(temp1,b)==b)){
		
		devide_help(temp1,temp5,temp3);
	}
	else{
		destroy(&temp2);destroy(&temp1);destroy(&temp4);destroy(&temp);
		return temp3;
	}
	
	
		

}

list moduli_help(list a,list b,list c)// devide list a by b;
{
	list temp;init(&temp);append(&temp,1);
	list temp1;init(&temp1);copy(&temp1,a);
	list temp2;init(&temp2);copy(&temp2,b);
	list temp3;init(&temp3);copy(&temp3,c);
	list temp5;init(&temp5);copy(&temp5,b);
	list temp4;init(&temp4);
	int n=0;
	
	for(int i=0;i<(length(temp1)-length(temp2)-1);i++){
		append(&temp,0);
	}
	
	temp2=multiply(temp2,temp);
	
	while(!(larger(temp1,temp2)==temp2)){
		temp1=subtraction(temp1,temp2);
		n++;
	}
	//printf("%d",n);
	append(&temp4,n);
	temp4=multiply(temp,temp4);
	if((temp4->data )<0){
		temp4->data=(temp4->data)* (-1);
	}
	temp3=addition(temp3,temp4);
	if((temp3->data) <0){
		temp3->data=(temp3->data)* (-1);
	}
	
	
	if(!(larger(temp1,b)==b)){
		
		moduli_help(temp1,temp5,temp3);
	}
	else{
		destroy(&temp2);destroy(&temp3);destroy(&temp4);destroy(&temp);
		return temp1;
	}
	
	
		

}



list devide(list m ,list n){
	list temp1=m;
	list temp2=n;
	nozero(&temp1);
	nozero(&temp2);
	if((n->data)==0){
		printf("error ! division by zero!");
		 list f;
		 init(&f);return f;
	}
	if(larger(temp1,temp2)==temp2){list c;init(&c);append(&c,0);return c;}
	if(length(m)==length(n) && length(m)==1){
		
		if((n->data)==1){return m;}
		if((m->data)==0){return m;}
	}
	list e;
	init(&e);append(&e,0);
	list d=devide_help(m,n,e);
	return d;
}


list moduli(list a,list b){
	fflush(stdin);
	list emp;init(&emp);insert(&emp,0);
	if((length(a))==1){
		if((a->data)==0){return emp;}
		
	}
	if(length(b)==1){
		if((b->data)==0){printf("error!");return emp;}
	}
	list d;init(&d);
	d=moduli_help(a,b,emp);
	
	
	return d;
		
}


int precedence(char c){
    if(c=='+' || c=='-'){return 10;}
    else if(c=='*' || c=='/' || c=='%'){return 20;}
    else if(c== '('){return 0;}
    else if (c=='^'){return 50;}
}



list calculate(list a,list b,char c){
	list temp;
	init(&temp);
	char p=c;
	
	switch (p){
		
		case '+' : temp=addition(a,b);
			    return temp;
			   
		case '-' : temp=subtraction(a,b);
			    return temp;
			    
		case '*' : temp=multiply(a,b);
			    return temp;
			    
		case '/' : temp=devide(a,b);
			    return temp;
			    
		case '%' : temp=moduli(a,b);
			    return temp;
			    
		case '^' : temp=power(a,b);
			    return temp;
			    
		default :  printf("invalid character\n");
			    return NULL;
	}
}



float convert(list a){

	list temp=a;
	int n,i=length(a)-1;
	float sum=0;
	while(temp){
		n=temp->data;
		sum=sum+pow(10,i)*n;
		i--;
		temp=temp->next;
	}
	sum= sum * PI / 180 ;
	return sum;
}

void sine(list a){
	list temp;init(&temp);
	list c=_360();
	temp=moduli(a,c);
	printf("sine of above angle is :% f",sin(convert(temp)));
}

void cosine(list a){
	list temp;init(&temp);
	list c=_360();
	temp=moduli(a,c);
	printf("cos of above angle is :% f",cos(convert(temp)));
}

void tangent(list a){
	list temp;init(&temp);
	list c=_360();
	temp=moduli(a,c);
	printf("tan of above angle is :% f",tan(convert(temp)));
}















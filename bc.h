
typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
}node;

typedef node* list;


//for doubly linked list

void init(list*);
void append(list*,int);
void insert(list*,int);
int length(list);
void traverse(list);


typedef struct o_stack{
    int top,size;
    char *arr;
}o_stack;

//for operand stack 
typedef struct stack{
    int top;
    int size;
    node **arr;
}p_stack;

//for operator
void o_init(o_stack *,int );
int o_isempty(o_stack );
void o_push(o_stack *,char );
void o_display(o_stack);
int o_isfull(o_stack );
char o_pop(o_stack *);
char o_peek(o_stack);
void o_destroy(o_stack *);

//for operand
void p_init(p_stack *,int );
int p_isempty(p_stack );
void p_push(p_stack *,node* );
int p_isfull(p_stack );
node* p_pop(p_stack *);
node* p_peek(p_stack);
void p_destroy(p_stack *);



//operation of linked lists
list addition(list ,list );
list subtraction(list ,list);
list multiply(list ,list);
list devide(list , list);
list devide_help(list ,list ,list);
list moduli_help(list ,list ,list);
list moduli(list ,list);
list power(list, list);
void sine(list);
void tangent(list);
void cosine(list);
void nozero(list *);
list larger(list ,list);
int precedence(char);
void copy(list *,list);
void destroy(list * );
float convert(list );

//calculate 

list calculate(list ,list , char );


//checking if given expression is valid or not : 
int check(char * );
int isoperator(char );
int isbracket(char );
























list addition(list ,list);
list subraction(list ,list);


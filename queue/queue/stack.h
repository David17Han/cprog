#define MAXITEM 10
#define EMPTY 1
#define NOTEMPTY 0
struct tagStack{
	int top;
	int pool[MAXITEM];
};
typedef struct tagStack Stack;

Stack* initStack();

void push(Stack * stack, char c);

char pop(Stack * stack);

int isStackEmpty(Stack *stack);

char* testIntMain(unsigned a,char * s);
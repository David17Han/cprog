#define  EMPTY 1
#define  NOTEMPTY 0

typedef struct queue{
	int front,rear;
	int a[10];
}Queue;

Queue* initQueue();


void enQueue(Queue * queue,char c);

char deQueue(Queue *queue);

int isQueueEmpty(Queue * queue);

char* testDoubleMain(double x,char * s);
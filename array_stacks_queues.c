#include <stdio.h>
#include <stdlib.h>

struct stackaddress{
    int * data;
    int top;
    int size;
};

typedef struct stackaddress * stackaddr;

stackaddr initStack(void)
{
    stackaddr s = malloc(sizeof(stackaddr));
    s->size = 5;
    s->data = malloc(s->size*sizeof(int));
    s->top = -1;
    return s;
}

void freeStack(stackaddr s)
{
	free(s->data);
	free(s);
}

int insertStack(stackaddr s, int val)
{
    if (s->top == s->size - 1)
    {
        printf("Stack Overflow while trying to insert %i\n", val);
        return -1;
    }

    if( val < 0 ) {return -3;} 

    else 
    {
        s->top = s->top + 1;
        s->data[s->top] = val;
        return val;
    }
}

int extractStack(stackaddr s)
{
    if (s->top < 0)
    {
        printf("Stack Underflow\n");
        return -2;
    }

    int returnelement = s->data[s->top];
    s->top--;
    return returnelement;
}



//===================================================================================================


struct queueaddress{
    int * data;
    int size;
    int n;
    int start;
};

typedef struct queueaddress * queueaddr;

queueaddr initQueue()
{
    queueaddr q = malloc(sizeof(queueaddr));
    q->n = 0;
    q->size = 5;
    q->data = malloc(q->size * sizeof(int));
    q->start = 0;
    return q;

}
void freeQueue(queueaddr q) 
{
    free(q->data);
	free(q);
}


int insertQueue(queueaddr q, int val)
{
    if (q->n == q->size)
    {
        printf("Queue Overflow\n");
        return -1;
    }

    if (val < 0){return -3;}

    q->data[(q->start + q->n) % q->size] = val;
    q->n++;
    return val;
}

int extractQueue(queueaddr q)
{
    if (q->n < 1)
    {
        printf("Queue Underflow\n");
        return -2;
        
    }
    
    int returnelement = q->data[q->start];
    q->start = (q->start + 1) % q->size;
    q->n--;
    return returnelement;

}






int main(void) 
{

	printf("Stack: ");
	stackaddr s = initStack();

	insertStack(s, 10);
	insertStack(s, 20);
	insertStack(s, 15);
	insertStack(s, 555);
    insertStack(s, 34);
    insertStack(s, 45);

	printf("%d ", extractStack(s));
	printf("%d ", extractStack(s));
	printf("%d ", extractStack(s));
	printf("%d ", extractStack(s));
    printf("%d ", extractStack(s));

	freeStack(s);

	printf("\n\nQueue: ");
	queueaddr q = initQueue();

	insertQueue(q, 10);
	insertQueue(q, 20);
	insertQueue(q, 30);
	insertQueue(q, 75);
    insertQueue(q, 23);

	printf("%d ", extractQueue(q));
    printf("%d ", extractQueue(q));
    printf("%d ", extractQueue(q));
    printf("%d ", extractQueue(q));

    printf("\nq->start: %i\n", q->start);

    printf("%d ", extractQueue(q));

    printf("\nq->start: %i\n", q->start);

    insertQueue(q, 53);

    printf("%d ", extractQueue(q));

    printf("\nq->start: %i\n", q->start);


	freeQueue(q);

	printf("\n\nDone!\n");
	return 0;
}
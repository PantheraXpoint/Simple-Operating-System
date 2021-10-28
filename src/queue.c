#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (proc != NULL && q->size < 10)
	{
		q->proc[q->size] = proc;
		q->size++;
	}
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	struct pcb_t *temp; temp = (struct pcb_t *)malloc(sizeof(struct pcb_t));
	temp = q->proc[0];
	int i; int pos; unsigned int max;
	pos = 0; max = q->proc[0]->priority;
	for (i = 1; i < q->size; i++)
	{
		if (max < q->proc[i]->priority) 
		{
			pos = i;
			max = q->proc[i]->priority;
			temp = q->proc[i];
		}
	}
	int j;
	for (j = pos; j < q->size; j++)
	{
		if (j == q->size - 1) break;
		q->proc[j] = q->proc[j+1];
	}
	q->proc[j] = NULL;
	q->size--;
	return temp;
}


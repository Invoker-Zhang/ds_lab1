#ifndef _STACK_H_
#define _STACK_H_

#define STACK_INIT_SIZE 100
typedef struct Stack{
	void *elem;
	unsigned int elemsize;
	int sp;
	int stacksize;
}Stack;

int StackInit(Stack &stk,unsigned int elemsize){
	if(elemsize=0)
		return 0;
	if(!(stk->elem=(void*)malloc(elemsize*STACK_INIT_SIZE)))
		return 0;
	stk->elemsize=elemsize;
	stk->sp=0;
	stk->sp=STACK_INIT_SIZE;
	return 1;
}
int Push(Stack &stk,void *p,
#endif

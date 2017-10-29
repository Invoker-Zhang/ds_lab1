#include <stdlib.h>
#include "Stack.h"

int StackInitD(struct StackD *stk){
	stk->array=(double *)malloc(sizeof(double)*STACK_INIT_SIZE);
	stk->sp=0;
	stk->stacksize=STACK_INIT_SIZE;
	return 1;
}
int PushD(struct StackD *stk,double elem){
	stk->array[stk->sp]=elem;
	stk->sp++;
	return 1;
}
double PopD(struct StackD *stk){
	stk->sp--;
	return stk->array[stk->sp];
}
int GetTopD(struct StackD stk,double *des){
	if(stk.sp==0)return 0;
	else {
		*des =stk.array[stk.sp-1];
		return 1;
	}
}

int StackInit(struct Stack *stk){
	stk->array=(int *)malloc(sizeof(int)*STACK_INIT_SIZE);
	stk->sp=0;
	stk->stacksize=STACK_INIT_SIZE;
	return 1;
}


int Push(struct Stack*stk,int elem){
	stk->array[stk->sp]=elem;
	stk->sp++;
	return 1;
}
int Pop(struct Stack *stk){
	stk->sp--;
	return stk->array[stk->sp];
}
int GetTop(struct Stack stk,int *des){
	if(stk.sp==0)return 0;
	else {
		*des =stk.array[stk.sp-1];
		return 1;
	}
}


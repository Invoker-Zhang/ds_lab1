#ifndef _STACK_H_
#define _STACK_H_

#define STACK_INIT_SIZE 100

struct StackD{
	double *array;
	int sp;
	int stacksize;
}stkdouble;
int StackInitD(struct StackD *stk);
int PushD(struct StackD* stk,double elem);
double PopD(struct StackD*stk);
int GetTopD(struct StackD stk,double *des);

struct Stack{
	int *array;
	int sp;
	int stacksize;
};

int StackInit(struct Stack *stk);
int Push(struct Stack *stk,int elem);
int Pop(struct Stack*stk);
int GetTop(struct Stack stk,int *);

#endif

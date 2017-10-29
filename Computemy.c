#include "MyStr.h"
#include "Stack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double Computemy(char symbol[][SYMBOL_SIZE],int num){
	int i=0;
	struct StackD stk;
	StackInitD(&stk);
	for(;i<num;i++){
		if(IsNumber(symbol[i][0]))
			PushD(&stk,NumOfStr(symbol[i]));
		else if(!IsChar(symbol[i][0])){
			double opa,opb;
			opb=PopD(&stk);
			opa=PopD(&stk);
			switch(symbol[i][0]){
				case '+':
					PushD(&stk,opa+opb);break;
				case '-':
					PushD(&stk,opa-opb);break;
				case '*':
					PushD(&stk,opa*opb);break;
				case '/':
					PushD(&stk,opa/opb);break;
				case '^':
					PushD(&stk,pow(opa,opb));break;
				default:printf("fail to parse the symbol:%s\n",symbol[i]);
					break;	
			}
		}
		else {
			if(StrEqu(symbol[i],"sin"))
				PushD(&stk,sin(PopD(&stk)));
			else if(StrEqu(symbol[i],"cos"))
				PushD(&stk,cos(PopD(&stk)));
			else if(StrEqu(symbol[i],"tan"))
				PushD(&stk,tan(PopD(&stk)));
			else if(StrEqu(symbol[i],"exp"))
				PushD(&stk,pow(EXP,PopD(&stk)));
			else 
				printf("fail to parse the symbol:%s\n",symbol[i]);
		}

	}
	return PopD(&stk);
}

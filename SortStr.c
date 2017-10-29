#include "MyStr.h"
#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>


int PriorOf(char *sym);

/*SortStr cut str into Symbols and store it in the des*/
int SortStr(const char *str,char des[][STRING_SIZE]){
	int i=0,desx=0,desy=0;
	while(str[i]){
		if(str[i]==' '){
			i++;
			continue;
		}
		else if(IsNumber(str[i])){
			for(;IsNumber(str[i]);i++){
				des[desx][desy]=str[i];
				desy++;
			}
		}
		else if(IsChar(str[i])){
			for(;IsChar(str[i]);i++){
				des[desx][desy]=str[i];
				desy++;
			}
		}
		else {
			des[desx][desy]=str[i];
			desy++;
			i++;
		}
		des[desx][desy]='\0';
		desx++;
		desy=0;
	}
	des[desx][0]='\0';
	return desx;
}

int IsNumber(char c){
	if(c>='0'&&c<='9')return 1;
	else return 0;
}

int IsChar(char c){
	if(c>='a'&&c<='z'||(c>='A'&&c<='Z'))return 1;
	else return 0;
}

/*Change strings from the normal sequence to easy-calculated form*/
int ChangeStr(char symbol[][STRING_SIZE],int num){
	int i=0;
	int index=0;
	int p[30]={0};
	struct Stack stk;
	StackInit(&stk);
	while(symbol[i][0]){
		if(IsNumber(symbol[i][0])){
			p[index]=i;
			index++;
		}
		else if(symbol[i][0]=='('){
			Push(&stk,i);
		}
		else if(symbol[i][0]==')'){
			int t=Pop(&stk);
			while(symbol[t][0]!='('){
				p[index]=t;
				index++;
				t=Pop(&stk);
			}
		}
		else {
			int t;
			while(GetTop(stk,&t)){
				if(PriorOf(symbol[i])>PriorOf(symbol[t])){
					break;
				}
				else{
					t=Pop(&stk);
					p[index]=t;
					index++;
				}
			}
			Push(&stk,i);
		}
		i++;
	}
	int j;
	while(GetTop(stk,&j)){
		p[index]=Pop(&stk);
		index++;
	}
	char temp[20][STRING_SIZE]={0};
	for(i=0;i<index;i++){
		StrCpy(symbol[p[i]],temp[i]);
	}
	for(i=0;i<num;i++){
		StrCpy(temp[i],symbol[i]);
	}
	return index;
}

int PriorOf(char *sym){
	switch(sym[0]){
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		case '^':return 3;
		case '(':return 0;
		return 3;
	}

}

void Substitude(char src[][STRING_SIZE],int num,double s){
	int tempint=(int )(s);
	char tempstr[STRING_SIZE];
	NumToStr(s,tempstr);
	for(int i=0;i<num;i++){

		if(StrEqu(src[i],"x"))
			StrCpy(tempstr,src[i]);
	}
}













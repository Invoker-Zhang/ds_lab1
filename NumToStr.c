#include "Stack.h"
#include <stdlib.h>
#include "MyStr.h"
#include <math.h>
#include <stdio.h>
double NumOfStr(char *str){
	/*
	int i=0;
	double sum=0;
	while(str[i]){
		sum=sum*10+(str[i]-'0');
		i++;
	}
	return sum;
	*/
	if(!str){
		printf("invalid reference!\n");
		return 0;
	}
	int i=0;
	int flag=1;
	if(str[i++]=='-')
		flag=0;
	for(;IsNumber(str[i]);i++);
	if(str[i]!='\0'&&str[i]!='.'){
		printf("invalid string,cant change to number\n");
		return 0;
	}
	if(str[i]=='\0'){
		int j=0;
		double sum=0;
		for(;str[j];j++)
			sum=sum*10+(str[j]-'0');
		return flag?sum:-sum;
	}
	else{
		i++;
		if(!IsNumber(str[i])){
			printf("invalid string,cant change to number\n");
			return 0;
		}
		i++;
		for(;IsNumber(str[i]);i++);
		if(str[i]){
			printf("invalid string,cant change to number\n");
			return 0;
		}
		int j=0;
		double sum=0;
		for(;IsNumber(str[j]);j++)
			sum=sum*10+str[j]-'0';	
		int tag=j;
		for(j++;str[j];j++)
			sum+=(str[j]-'0')*pow(0.1,j-tag);
		return flag?sum:-sum;
	}
	
}
void NumToStr(double src,char *des){
	/*
	int tempint =(int )(src);
	int i=0;
	struct Stack stk;
	StackInit(&stk);
	while(tempint){
		Push(&stk,tempint%10);
		tempint/=10;
	}
	while(GetTop(stk,&tempint)){
		tempint=Pop(&stk);
		des[i++]='0'+tempint;
	}
	des[i]='\0';
	*/
	int tempint =(int)(src*pow(10,6));
	int flag=1;
	struct Stack stk;
	StackInit(&stk);
	if(tempint<0)
		flag=0;
	tempint =abs(tempint);
	int i=0;
	for(;tempint;i++){
		Push(&stk,tempint%10);
		tempint/=10;
	}
	int j=0;
	if(flag==0)
		des[j++]='-';
	for(int ii=i;ii>6;ii--){
		tempint=Pop(&stk);
		des[j++]='0'+tempint;
	}
	if(i<=6){
		des[j++]='0';
		des[j++]='.';
		for(;i<6;i++)
			des[j++]='0';
		while(GetTop(stk,&tempint)){
			tempint=Pop(&stk);
			des[j++]='0'+tempint;
		}
	}
	else{
		des[j++]='.';
		for(i=6;i;i--){
			tempint=Pop(&stk);
			des[j++]='0'+tempint;
		}
	}
	des[j]='\0';
	
}


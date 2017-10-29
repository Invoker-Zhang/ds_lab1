#ifndef _MYSTR_H_
#define _MYSTR_H_
#define SYMBOL_SIZE 10
#define EXP 2.72
#define STRING_SIZE 10
int IsNumber(char c);

int IsChar(char c);

double NumOfStr(char *str);

void NumToStr(double src,char *des);

int SortStr(const char *str,char des[][STRING_SIZE]);

void Substitude(char src[][STRING_SIZE],int num,double s);

int ChangeStr(char str[][STRING_SIZE],int num);

double Computemy(char symbol[][SYMBOL_SIZE],int num);

int StrEqu(char *src,char *des);

int StrCpy(char *src,char *des);

#endif

main : Draw.c StrEqu.c StrCpy.c Stack.c Computemy.c SortStr.c NumToStr.c
	gcc -o main Draw.c StrEqu.c StrCpy.c Stack.c Computemy.c SortStr.c NumToStr.c -g -lm
test : test.c StrEqu.c StrCpy.c Stack.c Computemy.c SortStr.c NumToStr.c
	gcc -o test StrEqu.c StrCpy.c Stack.c Computemy.c SortStr.c NumToStr.c test.c -g -lm



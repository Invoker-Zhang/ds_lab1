#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "MyStr.h"

#define PIXEL_X 60
#define PIXEL_Y 30
#define Max(x,y) ((x>y)?x:y)
#define Min(x,y) ((x<y)?x:y)
double Parse(char *fx,double x){
	char ffx[20][SYMBOL_SIZE];
	int num=SortStr(fx,ffx);
	Substitude(ffx,num,x);
	int numsym=ChangeStr(ffx,num);
	return Computemy(ffx,numsym);
}


void main(){
	char fx[20];
	char gx[20];
	short Pixel[PIXEL_Y][PIXEL_X]={0};
	double a,b;
	printf("input fx:\n");
	gets(fx);
	printf("input gx:\n");
	gets(gx);
	printf("input a and b:\n");
	scanf("%lf,%lf",&a,&b);
	system("clear");
	double incx=(b-a)/(PIXEL_X-1);
	double max=Parse(fx,a);
	double min=max;
	for(int i=0;i<PIXEL_X;i++){
		double tempfx=Parse(fx,a+i*incx);
		double tempgx=Parse(gx,a+i*incx);
		max=Max(max,tempfx);
		max=Max(max,tempgx);
		min=Min(min,tempfx);
		min=Min(min,tempgx);
	}
	double incy=(max-min)/(PIXEL_Y-1);
	for(int i=0;i<PIXEL_X;i++){
		double tempfx=Parse(fx,a+i*incx);
		double tempgx=Parse(gx,a+i*incx);
		int indexfx=(int)((tempfx-min)/incy);
		int indexgx=(int)((tempgx-min)/incy);
		for(int j=Min(indexfx,indexgx);j<=Max(indexfx,indexgx);j++){
			Pixel[j][i]=1;
		}
	}
	for(int i=0;i<PIXEL_Y;i++){
		for(int j=0;j<PIXEL_X;j++){
			if(Pixel[PIXEL_Y-1-i][j])
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

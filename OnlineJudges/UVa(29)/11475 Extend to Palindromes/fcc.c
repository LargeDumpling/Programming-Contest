/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-08	File created.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define D 10000000
char tex1[D],tex2[D];
int main(int argc,char *argv[])
{
	int i;
	FILE *f1=fopen(argv[1],"r"),*f2=fopen(argv[2],"r");
	fread(tex1,1,D,f1); fread(tex2,1,D,f2);
	for(i=0;i<D;i++) if(tex1[i]!=tex2[i]) return 1;
	printf("No problem\n");
	return 0;
}


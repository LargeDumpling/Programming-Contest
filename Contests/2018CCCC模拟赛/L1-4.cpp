/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-03-25	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char A[15],B[15],C[15];
int main()
{
	A[0]=B[0]='\0';
	for(int i=1;true;i++)
	{
		gets(C);
		if(C[0]=='.') break;
		if(i==2) strcpy(A,C);
		else if(i==14) strcpy(B,C);
	}
	if(A[0]=='\0') printf("Momo... No one is for you ...");
	else if(B[0]=='\0') printf("%s is the only one for you...",A);
	else printf("%s and %s are inviting you to dinner...",A,B);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


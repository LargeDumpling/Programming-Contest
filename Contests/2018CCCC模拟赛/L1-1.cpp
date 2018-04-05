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
int N,top,len;
char str[1050],st[1050];
int main()
{
	int n;
	scanf("%d",&N); while(getchar()!='\n');
	gets(str);
	len=strlen(str);
	n=(len/N)+(int)(len%N!=0);
	for(int i=0;i<N;i++)
	{
		top=0;
		for(int j=0;j<n;j++)
			if(i+j*N<len) st[j]=str[i+j*N];
			else st[j]=' ';
		for(int j=n-1;0<=j;j--)
			putchar(st[j]);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


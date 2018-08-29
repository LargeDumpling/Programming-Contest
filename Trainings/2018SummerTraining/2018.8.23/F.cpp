/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-23	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int B,M,N;
int S[MAXN];
int main()
{
	scanf("%d%d",&B,&M);
	if(M%B)
	{
		printf("%d 0\n",M);
		printf("G");
		for(int i=1;i<M;i++)
			printf(" B");
		putchar('\n');
		for(int i=0;i<M;i++)
			for(int j=0;j<B;j++)
				printf("%d%c",(i*B+j)%M,j==B-1?'\n':' ');
	}
	else
	{
		printf("%d 0\n",(N=M/B)+1);
		for(int i=0;i<=N;i++)
			S[i]=i;
		for(int i=N+1;i<M;i++)
			S[i]=S[i-N];
		printf("G");
		for(int i=1;i<=N;i++)
			printf(" B");
		putchar('\n');
		for(int i=0;i<=N;i++)
			for(int j=0;j<B;j++)
				printf("%d%c",S[(i*B+j)%M],j==B-1?'\n':' ');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


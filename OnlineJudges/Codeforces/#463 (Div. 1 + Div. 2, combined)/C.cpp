/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-15	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int N,A,B,x,y;
int main()
{
	scanf("%d%d%d",&N,&A,&B);
	for(x=0;x*A<=N;x++) if((N-x*A)%B==0)
	{
		y=(N-x*A)/B;
		break;
	}
	if(N<x*A) printf("-1");
	else
	{
		int st=1;
		for(int i=1;i<=x;i++,st+=A)
		{
			for(int j=1;j<=A;j++)
				printf("%d ",j==A?st:st+j);
		}
		for(int i=1;i<=y;i++,st+=B)
		{
			for(int j=1;j<=B;j++)
				printf("%d ",j==B?st:st+j);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


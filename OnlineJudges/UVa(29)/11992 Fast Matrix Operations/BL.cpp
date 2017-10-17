/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-24	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[21][100050],n,m,q;
int anss,ansma,ansmi;
void add(int x1,int y1,int x2,int y2,int x)
{
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			num[i][j]+=x;
	return;
}
void change(int x1,int y1,int x2,int y2,int x)
{
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
			num[i][j]=x;
	return;
}
void query(int x1,int y1,int x2,int y2)
{
	anss=0;ansma=0;ansmi=2147483647;
	for(int i=x1;i<=x2;i++)
		for(int j=y1;j<=y2;j++)
		{
			anss+=num[i][j];
			ansma=max(ansma,num[i][j]);
			ansmi=min(ansmi,num[i][j]);
		}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("BL.out","w",stdout);
	int a,b,c,d,e,order;
	while(scanf("%d%d%d",&n,&m,&q)!=-1)
	{
		memset(num,0,sizeof(num));
		while(q--)
		{
			scanf("%d%d%d%d%d",&order,&a,&b,&c,&d);
			switch(order)
			{
				case 1:
					scanf("%d",&e);
					add(a,b,c,d,e);
					break;
				case 2:
					scanf("%d",&e);
					change(a,b,c,d,e);
					break;
				case 3:
					query(a,b,c,d);
					printf("%d %d %d\n",anss,ansmi,ansma);
					break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


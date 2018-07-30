/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=105;
char map[MAXN][MAXN];
int T_T,a,b,c;
void prefill()
{
	for(int i=0;i<=2*(b+c);i++)
		for(int j=0;j<=2*(a+b);j++)
			map[i][j]='.';
	return;
}
void print()
{
	for(int i=2*(b+c);0<=i;i--)
	{
		for(int j=0;j<=2*(a+b);j++)
			putchar(map[i][j]);
		putchar('\n');
	}
	return;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		prefill();
		for(int i=0;i<=2*c;i++)
		{
			if(i&1) for(int j=0;j<=2*a;j++)
				map[i][j]=(j&1)?'.':'|';
			else for(int j=0;j<=2*a;j++)
				map[i][j]=(j&1)?'-':'+';
		}
		for(int k=1;k<=2*b;k++)
		{
			if(k&1)
			{
				for(int i=0;i<=2*a;i++)
					map[2*c+k][i+k]=(i&1)?'.':'/';
				for(int i=0;i<=2*c;i++)
					map[i+k][2*a+k]=(i&1)?'.':'/';
			}
			else
			{
				for(int i=0;i<=2*a;i++)
					map[2*c+k][i+k]=(i&1)?'-':'+';
				for(int i=0;i<=2*c;i++)
					map[i+k][2*a+k]=(i&1)?'|':'+';
			}
		}
		print();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


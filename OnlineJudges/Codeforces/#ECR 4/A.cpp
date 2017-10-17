/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char tex[105];
int ex_gcd(int a,int b,int &x,int &y)
{
	if(!b) { x=1,y=0; return a; }
	else { int t=ex_gcd(b,a%b,y,x); y-=a/b*x; return t; }
}
void put_sub(char *tex,int len) { for(int i=0;i<len;i++,tex++) putchar(*tex); }
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int n,a,b,x,y;
	scanf("%d%d%d%s",&n,&a,&b,tex);
	/*int tem=ex_gcd(a,b,x,y);
	if(n%tem) printf("-1");
	else
	{
		tem=n/tem;
		x*=tem; y*=tem;
		while(x<0) x+=b,y-=a;
		while(x-b>=0) x-=b,y+=a;
		if(x>=0&&y>=0)
		{
			printf("%d\n",x+y);
			int l=0;
			for(int i=1;i<=x*a;i++)
			{
				putchar(tex[i-1]);
				if(!(i%a)) putchar('\n');
			}
			l=x*a;
			for(int i=0;i<y*b;i++)
			{
				if(i&&!(i%b)) putchar('\n');
				putchar(tex[i+l]);
			}
			putchar('\n');
			char *temp=tex;
			for(int i=0;i<x;i++)
			{
				put_sub(temp,a);
				if(y>0||i!=x-1) putchar('\n');
				temp+=a;
			}
			for(int i=0;i<y;i++)
			{
				put_sub(temp,b);
				if(i!=y-1) putchar('\n');
				temp+=b;
			}
		}
		else printf("-1");
	}*/
	x=y=0;
	while(n>0)
	{
		if(!(n%a))
		{
			x+=n/a;
			n=0;
			break;
		}
		else if(!(n%b))
		{
			y+=n/b;
			n=0;
			break;
		}
		n-=(a+b); x++; y++;
	}
	if(!n)
	{
		printf("%d\n",x+y);
		char *tem=tex;
		for(int i=0;i<x;i++)
		{
			put_sub(tem,a);
			putchar('\n');
			tem+=a;
		}
		for(int i=0;i<y;i++)
		{
			put_sub(tem,b);
			putchar('\n');
			tem+=b;
		}
	}
	else puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


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
	//freopen("A.in","r",stdin);
	//freopen("A_BL.out","w",stdout);
	int n,a,b,x,y;
	scanf("%d%d%d%s",&n,&a,&b,tex);
	int tem1=ex_gcd(a,b,x,y),tem2;
	if(n%tem1) printf("-1");
	else
	{
		tem2=n/tem1;
		x*=tem2; y*=tem2;
		while(x<0) x+=b/tem1,y-=a/tem1;
		while(x-b/tem1>=0) x-=b/tem1,y+=a/tem1;
		if(x>=0&&y>=0)
		{
			printf("%d\n",x+y);
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
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


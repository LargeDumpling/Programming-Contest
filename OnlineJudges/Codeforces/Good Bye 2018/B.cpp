/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-12-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,X[2],Y[2];
void read1n(int &x)
{
	char ch; bool neg=false;
	for(ch=getchar();ch<'0'||'9'<ch;ch=getchar())
		if(ch=='-') neg=true;
		else if(ch==-1) return;
	for(x=0;'0'<=ch&&ch<='9';ch=getchar())
		x=(x<<1)+(x<<3)+ch-'0';
	if(neg) x=-x;
	return;
}
int main()
{
	int x,y;
	read1n(n);
	X[0]=Y[0]=2147483647;
	X[1]=-X[0]; Y[1]=-Y[0];
	for(int i=1;i<=n;i++)
	{
		read1n(x);
		read1n(y);
		if(X[0]==x) Y[0]=min(Y[0],y);
		else if(x<X[0])
		{
			X[0]=x;
			Y[0]=y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		read1n(x);
		read1n(y);
		if(X[1]==x) Y[1]=max(Y[1],y);
		else if(X[1]<x)
		{
			X[1]=x;
			Y[1]=y;
		}
	}
	printf("%d %d",X[0]+X[1],Y[0]+Y[1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


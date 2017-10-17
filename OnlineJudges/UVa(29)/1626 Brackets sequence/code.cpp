/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-11-30	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T,f[105][105],lenth;
char tex[105];
int min(const int &a,const int &b){return a<b?a:b;}
bool PP(const char &A,const char &B)
{
	if(A=='(')
		return (B==')');
	if(A=='[')
		return (B==']');
	return false;
}
int dp(int l,int r)
{
	if(l>r)return 0;
	if(f[l][r]!=-1)return f[l][r];
	if(l==r)return f[l][r]=1;
	f[l][r]=2147483647;
	if(PP(tex[l],tex[r]))
		f[l][r]=min(f[l][r],dp(l+1,r-1));
	for(int i=l;i<r;i++)
		f[l][r]=min(f[l][r],dp(l,i)+dp(i+1,r));
	return f[l][r];
}
void print(int l,int r)
{
	if(l>r)return;
	if(l==r)
	{
		if(tex[l]=='['||tex[r]==']')
		{
			putchar('[');
			putchar(']');
		}
		else if(tex[l]=='('||tex[r]==')')
		{
			putchar('(');
			putchar(')');
		}
		return;
	}
	if(PP(tex[l],tex[r])&&f[l][r]==dp(l+1,r-1))
	{
		putchar(tex[l]);
		print(l+1,r-1);
		putchar(tex[r]);
		return;
	}
	for(int i=l;i<r;i++)
		if(f[l][r]==dp(l,i)+dp(i+1,r))
		{
			print(l,i);
			print(i+1,r);
			return;
		}
	return;
}
void read1n()
{
	char ch;
	lenth=0;
	for(ch=getchar();ch!='\n'&&ch!='['&&ch!=']'&&ch!='('&&ch!=')';ch=getchar());
	if(ch=='\n')return;
	for(;ch=='['||ch==']'||ch=='('||ch==')';ch=getchar())
		tex[++lenth]=ch;
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%d",&T);
	read1n();
	while(T--)
	{
		memset(f,-1,sizeof(f));
		//scanf("%s",tex+1);
		//lenth=strlen(tex+1);
		read1n();
		read1n();
		dp(1,lenth);
		print(1,lenth);
		putchar('\n');
		if(T)
			putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


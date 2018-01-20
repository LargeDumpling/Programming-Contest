/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-01-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int T_T,len,ans;
char A[30],B[30];
void read1n(char* &T,long long &x)
{
	bool neg=false;
	while(*T<'0'||'9'<*T)
		if(*(T++)=='-')
			neg^=true;
	x=0;
	while('0'<=*T&&*T<='9')
		x=(x<<1)+(x<<3)+*(T++)-'0';
	if(neg) x=-x;
	return;
}
bool check(int x)
{
	int type;
	char *T;
	long long a,b,c;
	for(int i=0;i<=len;i++)
	{
		B[i]=A[i];
		if(B[i]=='?') B[i]=x+'0';
	}
	read1n(T=B,a);
	if(*T=='*') type=0;
	else type=1;
	read1n(T,b);
	read1n(T,c);
	if(type==0&&a*b==c) return true;
	else if(type==1&&a+b==c) return true;
	return false;
}
bool exist[10];
int main()
{
	bool flag=false;
	scanf("%d",&T_T);
	while(T_T--)
	{
		memset(exist,false,sizeof(exist));
		scanf("%s",A);
		len=strlen(A);
		if(A[0]=='-'&&A[1]=='?') flag=true;
		for(int i=0;i<len;i++)
		{
			if(i&&'9'<A[i-1]&&A[i-1]<'0'&&A[i]=='-'&&A[i+1]=='?') flag=true;
			if('0'<=A[i]&&A[i]<='9')
				exist[A[i]-'0']=true;
		}
		ans=-1;
		for(int i=(int)flag;i<=9;i++)
			if(!exist[i]&&check(i))
			{
				ans=i;
				break;
			}
		printf("%d",ans);
		if(T_T) putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


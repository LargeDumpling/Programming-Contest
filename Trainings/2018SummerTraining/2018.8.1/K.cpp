/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-01	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=505;
int T_T,len;
char str[MAXN];
bool check(int l,int r)
{
	if(r<l) return false;
	if(l==r)
	{
		if(str[l]=='+'||str[l]=='*') return false;
		if(str[l]=='?') str[l]='1';
		return true;
	}
	for(int i=l;i<=r;i++)
	{
		if(str[i]=='+'||str[i]=='*')
			return check(l,i-1)&check(i+1,r);
		if(i==l&&str[i]=='0'&&i<r&&'0'<=str[i+1]&&str[i+1]<='9')
			return false;
		if(i==l&&str[i]=='0'&&i<r&&str[i+1]=='?')
			str[i+1]='+';
	}
	for(int i=l;i<=r;i++)
		if(str[i]=='?')
			str[i]='1';
	return true;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%s",str);
		len=strlen(str);
		if(check(0,len-1)) printf("%s\n",str);
		else puts("IMPOSSIBLE");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


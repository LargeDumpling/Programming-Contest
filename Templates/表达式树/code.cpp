/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2015-12-19	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int nc,lch[100050],rch[100050],op[100050];
int build_tree(char *s,int x,int y)
{
	int c1=-1,c2=-1,p=0,u;
	if(y-x==1)
	{
		u=++nc;
		lch[u]=rch[u]=0;
		op[u]=s[x];
		return u;
	}
	for(int i=x;i<y;i++)
	{
		switch(s[i])
		{
			case '(':p++;break;
			case ')':p--;break;
			case '+':case '-':if(!p)c1=i;break;
			case '*':case '/':if(!p)c2=i;break;
		}
	}
	if(c1<0)c1=c2;
	if(c1<0)return build_tree(s,x+1,y-1);
	u=++nc;
	lch[u]=build_tree(s,x,c1);
	rch[u]=build_tree(s,c1+1,y);
	op[u]=s[c1];
	return u;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


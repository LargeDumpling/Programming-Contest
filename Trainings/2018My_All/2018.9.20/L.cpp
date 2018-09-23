/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-09-20	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
int T_T,n,m;
char str[MAXN];
// 0 for left
// 1 for right
int calc(int p,int x)
{
	int ans=0;
	if(x==0)
	{
		while(p!=1)
			if(str[p--]=='R')
				ans++;
	}
	else if(x==1)
	{
		while(p!=n)
			if(str[p++]=='L')
				ans++;
	}
	return ans;
}
int main()
{
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",str+1);
		printf("%d\n",min(calc(m,0),calc(m,1)));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


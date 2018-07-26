/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-07-26	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=35;
int n,m,p[MAXN];
int main()
{
	int l,mid,r,res;
	scanf("%d%d",&m,&n);
	printf("%d\n",m);
	fflush(stdout);
	scanf("%d",&p[0]);
	if(p[0]==0) exit(0);
	p[0]=-p[0];
	for(int i=1;i<n;i++)
	{
		printf("%d\n",m);
		fflush(stdout);
		scanf("%d",&p[i]);
		p[i]=-p[i];
	}
	l=0; r=m;
	for(int i=0;l<r-1;i++)
	{
		mid=(l+r)>>1;
		printf("%d\n",mid);
		fflush(stdout);
		scanf("%d",&res);
		if(p[i%n]*res==0) exit(0);
		else if(p[i%n]*res==1) l=mid;
		else if(p[i%n]*res==-1) r=mid;
		else if(res==-2) exit(0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


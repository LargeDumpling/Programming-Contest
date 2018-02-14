/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-02-02	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200050;
int n;
int num[MAXN],f[MAXN];
char str[MAXN];
int fInd(int x)
{
	if(f[x]!=f[f[x]])
		f[x]=fInd(f[x]);
	return f[x];
}
void merge(int a,int b)
{
	a=fInd(a); b=fInd(b);
	if(a!=b)
	f[b]=a;
	return;
}
int main()
{
	bool flag=true;
	for(int i=0;i<MAXN;i++)
		f[i]=i;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	scanf("%s",str+1);
	for(int i=1;i<n;i++)
		if(str[i]=='1')
			merge(i,i+1);
	for(int i=1;i<=n;i++)
		if(fInd(i)!=fInd(num[i]))
			flag=false;
	puts(flag?"YES":"NO");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


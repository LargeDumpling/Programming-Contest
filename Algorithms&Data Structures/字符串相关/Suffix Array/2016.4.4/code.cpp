/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-04-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=100050;
char tex[MAXL];
int sa[MAXL],height[MAXL],c[MAXL],a[MAXL],b[MAXL],lenth;
void build_sa()
{
	int *x=a,*y=b,m=256,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<lenth;i++) c[x[i]=tex[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=lenth-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=MAXL;k<<=1)
	{
		p=0;
		for(int i=lenth-k;i<lenth;i++) y[p++]=i;
		for(int i=0;i<lenth;i++) if(k<=sa[i]) y[p++]=sa[i]-k;
		memset(c,0,sizeof(c));
		for(int i=0;i<lenth;i++) c[x[y[i]]]++;
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=lenth-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
	}
	return;
}
void build_height()
{
	int rank[MAXL];
	for(int i=0;i<MAXL;i++) rank[sa[i]]=i;
	height[0]=0;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%s",tex);
	lenth=strlen(tex);
	build_sa();
	build_height();
	for(int i=0;i<lenth;i++) printf("%d ",sa[i]); putchar('\n');
	for(int i=1;i<lenth;i++) printf("%d ",height[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


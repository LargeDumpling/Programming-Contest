/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-07-21	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
char tex[MAXN];
int sa[MAXN],num[2][MAXN],c[MAXN],lenth;
void show()
{
	static int cnt=0;
	fprintf(stderr,"\n%d\n",++cnt);
	for(int i=0;i<lenth;i++) fprintf(stderr,"%d ",sa[i]); putchar('\n');
	for(int i=0;i<lenth;i++) fprintf(stderr,"%d ",c[i]); putchar('\n');
	return;
}
void build_sa()
{
	int *x=num[0],*y=num[1],m=256,p;
	lenth=strlen(tex);
	memset(c,0,sizeof(c));
	memset(sa,0,sizeof(sa));
	for(int i=0;i<lenth;i++) c[x[i]=tex[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=lenth-1;i>=0;i--)
		sa[--c[x[i]]]=i;
	for(int i=0;i<lenth;i++)
		printf("%d ",sa[i]);
	for(int k=1;k<=lenth;k++)
	{
		show();
		p=0;
		for(int i=lenth-k;i<lenth;i++) y[p++]=i;
		for(int i=0;i<lenth;i++) if(k<=sa[i]) y[p++]=sa[i]-k;
		for(int i=0;i<lenth;i++) c[x[y[i]]]++;
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=lenth-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		x[sa[0]]=p=0;
		for(int i=1;i<lenth;i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]&&y[sa[i-1]+k])?p-1:p++;
		if(p<m);
	}
	return ;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	scanf("%s",tex);
	build_sa();
	fclose(stdin);
	fclose(stdout);
	return 0;
}


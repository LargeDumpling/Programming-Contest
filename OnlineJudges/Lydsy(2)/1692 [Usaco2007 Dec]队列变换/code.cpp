/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-04	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char T[60050];
int sa[60050],height[60050],a[60050],b[60050],c[60050],rank[60050],lenth;
void build_sa()
{
	int *x=a,*y=b,m=27,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<lenth;i++) c[x[i]=T[i]-'A']++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=lenth-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=lenth;k<<=1)
	{
		p=0;
		for(int i=lenth-1;i>=lenth-k;i--) y[p++]=i;
		for(int i=0;i<lenth;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		memset(c,0,sizeof(c));
		for(int i=0;i<lenth;i++) c[x[y[i]]]++;
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=lenth-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		x[sa[0]]=0;
		for(int i=p=1;i<lenth;i++)
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
		if(p>=lenth)break;
		m=p;
	}
	return;
}
int main()
{
	int len,l,r;
	scanf("%d",&len);
	lenth=len;
	for(int i=0;i<len;i++)
	{
		getchar();
		T[i]=getchar();
	}
	T[lenth]='Z'+1;
	for(int i=0;i<lenth;i++) T[(lenth<<1)-i]=T[i];
	lenth=lenth<<1|1;
	build_sa();
	for(int i=0;i<lenth;i++) rank[sa[i]]=i;
	l=0;r=len-1;
	for(int i=0;i<len&&l<r;i++)
	{
		if(i&&i%80==0) putchar('\n');
		if(rank[l]<rank[(len<<1)-r]) putchar(T[l++]);
		else putchar(T[(len<<1)-(r--)]);
	}
	putchar(T[l]);
	return 0;
}


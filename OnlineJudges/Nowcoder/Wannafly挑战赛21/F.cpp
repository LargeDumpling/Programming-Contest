/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2018-08-03	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100050;
char str[MAXN];
int len,sa[MAXN],rank[MAXN],height[MAXN];
int num[MAXN],bsa[MAXN],c[MAXN],ansp,ansc;
void build_sa()
{
	int *x=num,*y=bsa,m=26,p,i,k;
	for(i=0;i<m;i++) c[i]=0;
	for(i=0;i<len;i++) c[x[i]=str[i]-'a']++;
	for(i=1;i<m;i++) c[i]+=c[i-1];
	for(i=len-1;0<=i;i--) sa[--c[x[i]]]=i;
	for(k=1;k<=len;k<<=1)
	{
		p=0;
		for(i=len-1;len-k<=i;i--) y[p++]=i;
		for(i=0;i<len;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		for(i=0;i<m;i++) c[i]=0;
		for(i=0;i<len;i++) c[x[y[i]]]++;
		for(i=1;i<m;i++) c[i]+=c[i-1];
		for(i=len-1;0<=i;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;
		x[sa[0]]=0;
		for(i=1;i<len;i++)
			x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
		if(len<=p) break;
		m=p;
	}
	return;
}
void build_height()
{
	int k=0,j,i;
	for(i=0;i<len;i++) rank[sa[i]]=i;
	for(i=0;i<len;i++)
	{
		if(k) k--;
		if(!rank[i]) continue;
		j=sa[rank[i]-1];
		while(str[i+k]==str[j+k]) k++;
		height[rank[i]]=k;
	}
	return;
}
void calc(int l,int r,int x)
{
	if(r<l) return;
	for(int i=l+1;i<=r;i++)
		if(height[i]==0)
		{
			calc(l,i-1,x);
			calc(i,r,x);
			return;
		}
	int sum=min(x,len-sa[l]),curr;
	curr=min(sa[i]+x-1,);
	return;
}
int main()
{
	int Q,x;
	scanf("%s",str);
	len=strlen(str);
	build_sa();
	build_height();
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&x);
		ansp=ansc=0;
		calc(0,len-1,x);
		for(int i=0;i<x;i++)
			putchar(str[ansp+i]);
		printf(" %d\n",ansc);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


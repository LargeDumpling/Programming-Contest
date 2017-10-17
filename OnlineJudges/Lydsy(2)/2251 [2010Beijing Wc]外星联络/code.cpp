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
char T[3050];
int sa[3050],height[3050],a[3050],b[3050],c[3050],lenth;
void build_sa()
{
	int *x=a,*y=b,m=2,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<lenth;i++) c[x[i]=T[i]-'0']++;
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
void build_height()
{
	int rank[100050];
	for(int i=0;i<lenth;i++) rank[sa[i]]=i;
	height[rank[0]]=0;
	for(int i=0,k=0,j;i<lenth;i++)
	{
		if(k)k--;
		if(!rank[i])continue;
		j=sa[rank[i]-1];
		while(T[i+k]==T[j+k])k++;
		height[rank[i]]=k;
	}
	return;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	scanf("%d",&lenth);
	scanf("%s",T);
	build_sa();
	build_height();
	for(int l=1,r;l<lenth;l++)
	{
		for(int h=height[l-1]+1;h<=height[l];h++)
		{
			r=l+1;
			while(height[r]>=h)r++;
			printf("%d\n",r-l+1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


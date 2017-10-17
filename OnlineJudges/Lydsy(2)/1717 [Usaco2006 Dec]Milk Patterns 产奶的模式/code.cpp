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
int sa[100050],height[100050],a[100050],b[100050],c[1000050],T[100050],lenth,k;
void build_sa()
{
	int *x=a,*y=b,m=1000001,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<lenth;i++) c[x[i]=T[i]]++;
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
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<lenth;i++)
	{
		if(height[i]>=x) cnt++;
		else
		{
			if(cnt+1>=k) return true;
			cnt=0;
		}
	}
	if(cnt+1>=k)return true;
	return false;
}
int main()
{
	freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	int l,r,mid;
	scanf("%d%d",&lenth,&k);
	for(int i=0;i<lenth;i++) scanf("%d",&T[i]);
	build_sa();
	build_height();
	l=0;r=lenth+1;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%d",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


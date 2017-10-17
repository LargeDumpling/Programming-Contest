/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-05	File created.
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=40050;
char T[MAXL];
int sa[MAXL],height[MAXL],a[MAXL],b[MAXL],c[MAXL],lenth,m;
void build_sa()
{
	int *x=a,*y=b,m=26,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<lenth;i++) c[x[i]=T[i]-97]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=lenth-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<lenth;k<<=1)
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
	int rank[MAXL];
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
	int cnt=1;
	for(int r=1;r<=lenth;r++)
	{
		if(r==lenth||height[r]<x)
		{
			if(cnt>=m) return true;
			cnt=1;
		}
		else cnt++;
	}
	return false;
}
int rightmost(int x)
{
	int cnt=1,ans=0,l=0;
	for(int r=1;r<=lenth;r++)
	{
		if(r==lenth||height[r]<x)
		{
			if(cnt>=m)
			{
				for(int i=l;i<r;i++)
				{
					ans=max(ans,sa[i]);
				}
			}
			cnt=1;
			l=r;
		}
		else cnt++;
	}
	return ans;
}
void solve()
{
	int l,r,mid;
	if(!check(1))puts("none");
	else
	{
		l=0; r=lenth+1;
		while(l<r-1)
		{
			mid=(l+r)>>1;
			if(check(mid)) l=mid;
			else r=mid;
		}
		if(l==lenth) printf("%d 0\n",l);
		else printf("%d %d\n",l,rightmost(l));
	}
	return;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	while(scanf("%d",&m)!=-1&&m)
	{
		scanf("%s",T);
		lenth=strlen(T);
		build_sa();
		build_height();
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


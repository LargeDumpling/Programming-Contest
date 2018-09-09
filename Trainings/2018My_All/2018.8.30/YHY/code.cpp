/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-06	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=100050;
char T[MAXL];
int sa[MAXL],height[MAXL],c[MAXL],t1[MAXL],t2[MAXL],rank[MAXL],lenth;
void build_sa()
{
	int *x=t1,*y=t2,m=26,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<lenth;i++) c[x[i]=T[i]-97]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=lenth-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=lenth;k<<=1)
	{
		p=0;
		for(int i=lenth-k;i<lenth;i++) y[p++]=i;
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
void bulid_height()
{
	for(int i=0;i<lenth;i++) rank[sa[i]]=i;
	height[rank[0]]=0;
	for(int i=1,k=0,j;i<lenth;i++)
	{
		if(k) k--;
		if(!rank[i])continue;
		j=sa[rank[i]-1];
		while(T[i+k]==T[j+k])k++;
		height[rank[i]]=k;
	}
	return;
}
int solve1(int a,int b)
{//最长公共前缀
	//转换为排行为a的后缀和排行为b的后缀的最长公共前缀缀b的最长公共前缀
	int ans=0;
	a=rank[a]; b=rank[b];
	if(a>b) swap(a,b);
	for(int i=a+1;i<=b;i++) ans=max(ans,height[i]);//这是暴力写法
	//因为是RMQ问题，所以可以有更优的做法
	return ans;
}
int solve2()
{//可重叠最长重复子串
	//因为可重叠重复子串都是某些后缀的公共前缀，所以问题转换为求后缀间最长的公共前缀
	int ans=0;
	for(int i=0;i<lenth;i++) ans=max(ans,height[i]);
	//扫一遍，O(n)
	return ans;
}
bool solve3_check(int x,int k)
{
	int cnt=1;
	for(int i=0;i<=lenth;i++)
	{
		if(i==lenth||height[i]<x)
		{
			if(cnt>=k)return true;
			cnt=1;
		}
		else cnt++;
	}
	return false;
}
int solve3(int k)
{//可重叠的k次最长重复子串
	//问题转换为求一个最长的至少为k个后缀的公共前缀的子串，可二分答案
	int l,r,mid;
	if(!solve3_check(1,k))return 0;
	l=1; r=lenth+1;
	while(l<r-1)
	{
		mid=(l+r)>>1;
		if(solve3_check(mid,k)) l=mid;
		else r=mid;
	}
	return l;
}
bool solve4_check(int x)
{
}
int solve4()
{//不可重叠的最长重叠子串
	//将后缀分为若干个公共前缀大于x的组，因为不可重叠，所以每个组的最大sa值差应大于等于长度x
}
int main()
{
	return 0;
}


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
{//�����ǰ׺
	//ת��Ϊ����Ϊa�ĺ�׺������Ϊb�ĺ�׺�������ǰ׺׺b�������ǰ׺
	int ans=0;
	a=rank[a]; b=rank[b];
	if(a>b) swap(a,b);
	for(int i=a+1;i<=b;i++) ans=max(ans,height[i]);//���Ǳ���д��
	//��Ϊ��RMQ���⣬���Կ����и��ŵ�����
	return ans;
}
int solve2()
{//���ص���ظ��Ӵ�
	//��Ϊ���ص��ظ��Ӵ�����ĳЩ��׺�Ĺ���ǰ׺����������ת��Ϊ���׺����Ĺ���ǰ׺
	int ans=0;
	for(int i=0;i<lenth;i++) ans=max(ans,height[i]);
	//ɨһ�飬O(n)
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
{//���ص���k����ظ��Ӵ�
	//����ת��Ϊ��һ���������Ϊk����׺�Ĺ���ǰ׺���Ӵ����ɶ��ִ�
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
{//�����ص�����ص��Ӵ�
	//����׺��Ϊ���ɸ�����ǰ׺����x���飬��Ϊ�����ص�������ÿ��������saֵ��Ӧ���ڵ��ڳ���x
}
int main()
{
	return 0;
}


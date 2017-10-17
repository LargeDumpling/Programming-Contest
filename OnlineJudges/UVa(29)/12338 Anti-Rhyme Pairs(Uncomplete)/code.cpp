/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-01-08	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,lenth,stp[100050];
char tex[1100050];
int sa[1100050],c[1100050],t1[1100050],t2[1100050],rank[1100050],height[1100050];
void build_sa()
{
	int *x=t1,*y=t2,m=256,p;
	for(int i=0;i<m;i++) c[i]=0;
	for(int i=0;i<lenth;i++) c[x[i]=tex[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=lenth-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=lenth;k<<=1)
	{
		p=0;
		for(int i=lenth-1;i>=lenth-k;i--) y[p++]=i;
		for(int i=0;i<lenth;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		for(int i=0;i<lenth;i++) c[x[y[i]]]++;
		for(int i=0;i<m;i++) c[i]+=c[i-1];
		for(int i=lenth-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		x[sa[0]]=0;
		for(int i=p=1;i<lenth;i++)
			x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		if(p>=lenth) break;
		m=p;
	}
	return;
}
void build_height()
{
	for(int i=0;i<lenth;i++) rank[sa[i]]=i;
	height[rank[0]]=0;
	for(int i=0,k=0,j;i<lenth;i++)
	{
		if(k) k--;
		if(!rank[i]) continue;
		j=sa[rank[i]-1];
		while(tex[i+k]==tex[j+k]) k++;
		height[rank[i]]=k;
	}
	return;
}
void build_RMQ(int a,int b)
{
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int T_T,temp,a,b;
	scanf("%d",&T_T);
	for(int cAse=1;cAse<=T_T;cAse++)
	{
		printf("Case %d:\n",cAse);
		scanf("%d",&n);
		temp=0;
		for(int i=1;i<=n;i++)
		{
			stp[i]=temp;
			scanf("%s",tex+temp);
			temp+=strlen(tex+temp);
			tex[temp++]='^'jk;
		}
		lenth=temp;
		build_sa();
		build_height();
		build_RMQ();
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			printf("%d\n",RMQ(sta[a],sta[b]));
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


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
char T[500050];
int sa[500050],height[500050],a[500050],b[500050],c[500050],lenth;
void build_sa()
{
	int *x=a,*y=b,m=26,p;
	memset(c,0,sizeof(c));
	for(int i=0;i<lenth;i++) c[x[i]=T[i]-97]++;
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
	int rank[500050];
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
int l[500050],r[500050],h[500050];
int s[500050],top;
long long solve()
{
	long long ans=(long long)(lenth-1)*lenth*(lenth+1)/2;
	memset(l,0,sizeof(l)); memset(r,0,sizeof(r));
	/*for(int i=1;i<lenth;i++)
	{
		l[i]=i-1;
		if(h[l[i]]>=h[i]&&l[l[i]]!=l[i]) l[i]=l[l[i]];
	}
	r[lenth-1]=lenth-1;
	for(int i=lenth-2;i>=0;i--)
	{
		r[i]=i+1;
		if(h[r[i]]>h[i]&&r[r[i]]!=r[i]) r[i]=r[r[i]];
	}
	for(int i=1;i<lenth;i++)
		ans-=2LL*(i-l[i])*(r[i]-i)*height[i];*/
	for(int i=0;i<lenth;i++) h[i+1]=height[i];
	h[0]=-2147483647;
	memset(s,top=0,sizeof(s));
	for(int i=1;i<=lenth;i++)
	{
		while(h[i]<=h[s[top]])top--;
		if(s[top]==0)l[i]=1;
		else l[i]=s[top]+1;
		s[++top]=i;
	}
	s[top=0]=lenth+1;h[lenth+1]=-2147483647;
	for(int i=lenth;i;i--)
	{
		while(h[i]<h[s[top]])top--;
		if(s[top]==lenth+1)r[i]=lenth;
		else r[i]=s[top]-1;
		s[++top]=i;
	}
	for(int i=1;i<=lenth;i++)
		ans-=2LL*(i-l[i]+1)*(r[i]-i+1)*h[i];
	return ans;
}
int main()
{
	//freopen("code.in","r",stdin);
	//freopen("code.out","w",stdout);
	scanf("%s",T);
	lenth=strlen(T);
	build_sa();
	build_height();
	printf("%lld",solve());
	fclose(stdin);
	fclose(stdout);
	return 0;
}


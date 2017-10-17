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
const int MAXL=200050;
int lenth,sa[MAXL],c[MAXL],t1[MAXL],t2[MAXL],rank[MAXL],height[MAXL];
char tex[MAXL];
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
		for(int i=0;i<m;i++) c[i]=0;
		for(int i=0;i<lenth;i++) c[x[y[i]]]++;
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=lenth-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		x[sa[0]]=0;
		for(int i=p=1;i<lenth;i++)
			x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
		if(p>=lenth) break;
		m=p;
	}
	return;
}
void build_height()
{
	int j,k=0;
	for(int i=0;i<lenth;i++) rank[sa[i]]=i;
	height[rank[0]]=0;
	for(int i=0;i<lenth;i++)
	{
		if(k) k--;
		if(!rank[i]) continue;
		j=sa[rank[i]-1];
		while(tex[i+k]==tex[j+k])k++;
		height[rank[i]]=k;
	}
	return;
}
int find()
{
	int ans=0;
	//for(int i=1;i<(lenth<<1);i++) if(sa[i]<lenth)
		//height[i]=min(height[i],lenth-sa[i]);
	//k=height[rankd
	for(int i=rank[lenth]-1,k=height[rank[lenth]];i>=0;i--)
	{
		if(sa[i]<lenth&&sa[i]+k>=lenth&&(lenth-sa[i])>ans)
			ans=lenth-sa[i];
		k=min(k,height[i]);
		//if(sa[i]<k)
	}
	for(int i=rank[lenth]+1,k=2147483647;i<(lenth<<1);i++)
	{
		k=min(k,height[i]);
		if(sa[i]<lenth&&sa[i]+k>=lenth&&(lenth-sa[i])>ans)
			ans=lenth-sa[i];
	}
	return ans;
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("SA.out","w",stdout);
	while(scanf("%s",tex)!=-1)
	{
		lenth=strlen(tex);
		for(int i=0;i<lenth;i++) tex[(lenth<<1)-1-i]=tex[i];
		tex[lenth<<1]=tex[lenth<<1|1]='\0';
		lenth<<=1;
		build_sa();
		build_height();
		//for(int i=0;i<lenth;i++) printf("%d ",sa[i]); putchar('\n');
		//for(int i=0;i<lenth;i++) printf("%d ",rank[i]); putchar('\n');
		//for(int i=0;i<lenth;i++) printf("%d ",height[i]); putchar('\n');
		lenth>>=1;
		for(int i=0;i<lenth;i++) putchar(tex[i]);
		printf("%s\n",tex+lenth+find());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


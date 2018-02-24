/*
 Author: LargeDumpling
 Email: LargeDumpling@qq.com
 Edit History:
	2016-03-13	File created.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXL=100050;
int lenth,sa[MAXL],height[MAXL],f[MAXL][18],Log[MAXL];
char tex[MAXL];
void build_sa()
{
	int c[MAXL],J[MAXL],P[MAXL],*x=J,*y=P,m=256,p;
	memset(c,0,sizeof(c));
	memset(J,0,sizeof(J));
	memset(P,0,sizeof(P));
	for(int i=0;i<lenth;i++) c[x[i]=tex[i]]++;
	for(int i=1;i<m;i++) c[i]+=c[i-1];
	for(int i=lenth-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=lenth;k<<=1)
	{
		p=0;
		for(int i=lenth-k;i<lenth;i++) y[p++]=i;
		for(int i=0;i<lenth;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		for(int i=0;i<m;i++) c[i]=0;
		for(int i=0;i<lenth;i++) c[x[y[i]]]++;
		for(int i=1;i<m;i++) c[i]+=c[i-1];
		for(int i=lenth-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		x[sa[0]]=0;
		for(int i=p=1;i<lenth;i++)
			x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
		if(lenth<=p) break;
		m=p;
	}
	return;
}
void build_height()
{
	int rank[MAXL],k=0;
	for(int i=0;i<lenth;i++) rank[sa[i]]=i;
	for(int i=0,j;i<lenth;i++)
	{
		if(k) k--;//k=h[i]>=h[i-1]-1
		j=sa[rank[i]-1];
		while(tex[i+k]==tex[j+k]) k++;
		height[rank[i]]=k;
	}
	return;
}
void RMQ_pre()
{
	memset(f,0,sizeof(f));
	Log[0]=-2;
	for(int i=0;i<lenth;i++)
	{
		f[i][0]=height[i];
		Log[i]=Log[i>>1]+1;
	}
	for(int j=1;j<18;j++)
		for(int i=0;i+(1<<j)<lenth;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	return;
}
int RMQ(int L,int R)
{
	if(R<=L) return -1;
	int t=Log[R-L],tem;
	tem=1<<t;
	return min(f[L][t],f[R-tem+1][t]);
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	scanf("%s",tex);
	lenth=strlen(tex);
	tex[lenth]='%';
	build_sa();
	build_height();
	RMQ_pre();
	fclose(stdin);
	fclose(stdout);
	return 0;
}


//LargeDumpling
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=5000;
const int M=4096;
struct jz
{
	int r,id;
	long double p;
	jz() { p=1; }
}v[MAXN];
int n,Log[MAXN];
vector<jz> d[M<<1];
bool cmp(jz A,jz B)
{
	if(A.id==1) return false;
	else if(B.id==1) return true;
	return A.r>B.r;
}
int main()
{
	Log[0]=-1;
	for(int i=1;i<MAXN;i++)
		Log[i]=Log[i>>1]+1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i].r;
		v[i].id=i;
	}
	sort(v+1,v+n+1,cmp);
	for(int i=1;i<=n;i++)
		cerr<<"("<<v[i].r<<","<<v[i].p<<","<<v[i].id<<")"<<endl;
	int height=Log[n],rem;
	//cerr<<height<<endl;
	rem=n-(1<<height); rem<<=1;
	for(int i=0,st=1<<(height+1);i<rem;i++)
		d[st+i].push_back(v[i+1]);
//	for(int i=1;i<=9;i++)
//	{
//		cerr<<"d["<<i<<"]"<<endl;
//		for(unsigned j=0;j<d[i].size();j++)
//			cerr<<"("<<d[i][j].r<<","<<d[i][j].p<<","<<d[i][j].id<<")"<<endl;
//	}
	for(int i=1,st=(1<<(height+1));i+rem<=n;i++)
		d[st-i].push_back(v[n-i+1]);
	for(int k=(1<<height)+(rem>>1)-1;k;k--)
	{
		for(unsigned i=0;i<d[k<<1].size();i++)
		{
			jz tem;
			tem.r=d[k<<1][i].r;
			tem.p=0;
			tem.id=d[k<<1][i].id;
			for(unsigned j=0;j<d[k<<1|1].size();j++)
				tem.p+=d[k<<1|1][j].p*d[k<<1][i].r/(d[k<<1][i].r+d[k<<1|1][j].r);
			tem.p*=d[k<<1][i].p;
			d[k].push_back(tem);
		}
		for(unsigned i=0;i<d[k<<1|1].size();i++)
		{
			jz tem;
			tem.r=d[k<<1|1][i].r;
			tem.p=0;
			tem.id=d[k<<1|1][i].id;
			for(unsigned j=0;j<d[k<<1].size();j++)
				tem.p+=d[k<<1][j].p*d[k<<1|1][i].r/(d[k<<1|1][i].r+d[k<<1][j].r);
			tem.p*=d[k<<1|1][i].p;
			d[k].push_back(tem);
		}
	}
//	for(int i=1;i<=9;i++)
//	{
//		cerr<<"d["<<i<<"]"<<endl;
//		for(unsigned j=0;j<d[i].size();j++)
//			cerr<<"("<<d[i][j].r<<","<<d[i][j].p<<","<<d[i][j].id<<")"<<endl;
//	}
	long double ans=0;
	for(unsigned i=0;i<d[1].size();i++)
		if(d[1][i].id==1)
			ans=max(ans,d[1][i].p);
	printf("%.10f",(double)ans);
	return 0;
}


